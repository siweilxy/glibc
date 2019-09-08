/*
 * master.cpp
 *
 *  Created on: Sep 6, 2019
 *      Author: siwei
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include "common.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

char buf[512];
extern int cpus;
extern socketFd_t socketPair[512];

int findIdbyPid(int pid)
{
    for(int i = 1;i<=32;i++)
    {
       if(socketPair[i].pid == pid)
       {
           return i;
       }
    }
    return -1;
}

void setnonblcokingmode(int fd)
{
    int ret = fcntl(fd, F_GETFL, 0);
    int r = 0;
    //printf("1.ret is %d\n", ret);
    r = fcntl(fd, F_SETFL, ret | O_NONBLOCK);
    //printf("r is %d\n", r);
}

int master_nonblock()
{
    int success = 0;
    printf("进入master函数\n");
    struct epoll_event* ep_events;
    struct epoll_event event;
    char buf_write[512] = "master msg";
    msg_t msg =
    { 0 };
    int epfd, event_cnt;
    epfd = epoll_create(50);
    int len = 0;
    int size = 0;
    int status = 0;
    int ret = 0;
    ep_events = (epoll_event*) malloc(sizeof(struct epoll_event) * 50);
    event.events = EPOLLIN | EPOLLET;
    for (int i = 1; i <= cpus; i++)
    {
        setnonblcokingmode(socketPair[i].socketfd[1]);
        event.data.fd = socketPair[i].socketfd[1];
        //printf("event.data.fd is %d,i is %d\n", event.data.fd, i);
        epoll_ctl(epfd, EPOLL_CTL_ADD, socketPair[i].socketfd[1], &event);

        msg.id = i;
        msg.order = order_start;
        memcpy(buf_write, &msg, sizeof(msg));
        int size = write(socketPair[i].socketfd[1], buf_write,
                strlen(buf_write));
        if (size <= 0)
        {
            printf("errno is %d,%s i is %d\n", errno, strerror(errno), i);
        } else
        {
            printf("发送开始指令到%d\n", i);
            success++;
        }
    }

    while (1)
    {
        event_cnt = epoll_wait(epfd, ep_events, 50, -1);
        if (event_cnt == -1)
        {
            printf("epoll_wait error\n");
            break;
        }
        for (int i = 0; i < event_cnt; i++)
        {
            while (1)
            {
                memset(buf, 0, sizeof(buf));
                len = read(ep_events[i].data.fd, buf, sizeof(msg_t));
                if (len == 0)
                {
                    printf("len == 0!!!!!!!!!!\n");
                } else if (len < 0)
                {
                    if (errno == EAGAIN)
                    {
                        //printf("read EAGAIN,break\n");
                        break;
                    }
                } else
                {
                    printf("收到消息\n");
                    msg = *(msg_t*) buf;

                    switch (msg.result)
                    {
                    case order_success:
                    {
                        printf("%d 执行任务成功\n", msg.id);
                        msg.order = order_end;
                        memcpy(buf_write, &msg, sizeof(msg));
                        int size = write(ep_events[i].data.fd, buf_write,
                                sizeof(msg_t));
                        if (size <= 0)
                        {
                            printf("errno is %d,%s id is %d\n", errno,
                                    strerror(errno), msg.id);
                        }

                        printf("发送停止指令成功 %d\n", msg.id);
                        ret = waitpid(msg.pid, &status, 0);
                        if (ret > 0)
                        {
                            success--;
                            printf("status is %d,ret is %d\n", status, ret);
                        } else
                        {
                            printf("ret is %d,status is %d\n", ret, status);
                        }

                        break;
                    }
                    case order_failed:
                    {
                        printf("%i 执行任务失败\n", msg.pid);
                        break;
                    }
                    default:
                    {
                        printf("%i 返回值不正确\n", msg.pid);
                    }
                    }
                }
            }
        }

        while (success == 0)
        {
            printf("success is %d\n",success);
            for (int i = 1; i <= cpus; i++)
            {
                printf("开始检测进程状态\n");
                while (success != 0)
                {
                    ret = waitpid(socketPair[i].pid, &status, 0);
                    if (ret > 0)
                    {
                        success--;
                        printf("i is %d status is %d,ret is %d\n", i, status,
                                ret);
                    } else
                    {
                        printf("i is %d ret is %d,status is %d\n", i, ret,
                                status);
                    }
                }
            }
        }
        printf("任务执行结束\n");
        break;
    }

    printf("离开master函数\n");
    return 0;
}

int master()
{
    printf("进入master函数\n");
    struct epoll_event* ep_events;
    struct epoll_event event;
    int epfd, event_cnt;
    epfd = epoll_create(50);

    ep_events = (epoll_event*) malloc(sizeof(struct epoll_event) * 50);
    event.events = EPOLLIN;
    for (int i = 1; i <= cpus; i++)
    {
        event.data.fd = socketPair[i].socketfd[1];
        printf("event.data.fd is %d,i is %d\n", event.data.fd, i);
        epoll_ctl(epfd, EPOLL_CTL_ADD, socketPair[i].socketfd[1], &event);
    }

    while (1)
    {
        //printf("epoll_wait start\n");
        event_cnt = epoll_wait(epfd, ep_events, 50, -1);
        if (event_cnt == -1)
        {
            printf("epoll_wait error\n");
            break;
        }
        for (int i = 0; i < event_cnt; i++)
        {
            printf("event_cnt is %d\n", event_cnt);
            memset(buf, 0, sizeof(buf));
            read(ep_events[i].data.fd, buf, sizeof(buf));
            printf("buf is %s, i is %d,fd is %d\n", buf, i,
                    ep_events[i].data.fd);
        }
    }
    printf("离开master函数\n");
    return 0;
}
