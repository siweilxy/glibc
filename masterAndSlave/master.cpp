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

char buf[512];
extern int cpus;
extern socketFd_t socketPair[512];

int master()
{
    printf("进入master函数\n");
    struct epoll_event* ep_events;
    struct epoll_event event;
    int epfd, event_cnt;
    epfd = epoll_create(50);

    ep_events=(epoll_event*)malloc(sizeof(struct epoll_event)*50);
    event.events=EPOLLIN;
    for(int i = 1;i<=cpus;i++)
    {
        event.data.fd = socketPair[i].socketfd[1];
        printf("event.data.fd is %d,i is %d\n",event.data.fd,i);
        epoll_ctl(epfd,EPOLL_CTL_ADD,socketPair[i].socketfd[1],&event);
    }

    while(1)
    {
        //printf("epoll_wait start\n");
        event_cnt = epoll_wait(epfd,ep_events,50,-1);
        if(event_cnt == -1)
        {
            printf("epoll_wait error\n");
            break;
        }
        for(int i=0;i<event_cnt;i++)
        {
            printf("event_cnt is %d\n",event_cnt);
            memset(buf,0,sizeof(buf));
            read(ep_events[i].data.fd, buf, sizeof(buf));
            printf("buf is %s, i is %d,fd is %d\n", buf,i,ep_events[i].data.fd);
        }
    }
    printf("离开master函数\n");
    return 0;
}
