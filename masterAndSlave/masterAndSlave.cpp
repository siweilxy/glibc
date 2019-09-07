/*
 * masterAndSlave.cpp
 *
 *  Created on: Sep 6, 2019
 *      Author: siwei
 */

#include <unistd.h>
#include <stdio.h>
#include <sched.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include "common.h"
#include <errno.h>
#include <string.h>

int cpus = 4;
socketFd_t socketPair[512]={0};

int masterAndSlave()
{
    cpus = sysconf( _SC_NPROCESSORS_CONF);
    int ret = 0;
    pid_t pid;
    printf("%d cpus,master pid is %d\n", cpus, getpid());
    for (int i = 1; i <= cpus; i++)
    {
        ret = socketpair(AF_UNIX,SOCK_STREAM,0,socketPair[i].socketfd);
        if(ret < 0 )
        {
            printf("socketpair failed ,i is %d,errno is %s",i,strerror(errno));
            return -1;
        }
        pid = fork();
        if (pid > 0)
        {
            printf("this is master,init %d slaves,master pid is %d\n", i,getpid());
            if(i == cpus)
            {
                printf(RED "i is %d,slaves init complete\n " NONE,i);
                ret = master();
                if(ret != 0)
                {
                    printf("master is error\n");
                    break;
                }
            }
        } else if (pid == 0)
        {
            printf("this is %d child,pid is %d\n", i,getpid());
            ret = slave(i);
            if(ret != 0 )
            {
                printf("slave 返回失败\n");
                exit(1);
            }else
            {
                printf("slave 返回成功\n");
                exit(0);
            }

        }
    }

    return 0;
}
