/*
 * slave.cpp
 *
 *  Created on: Sep 6, 2019
 *      Author: siwei
 */

#include <stdio.h>
#include <unistd.h>
#include "common.h"
#include <string.h>
#include <stdlib.h>
#include <errno.h>

extern socketFd_t socketPair[512];
char str[]="slave%d_rand_%d";

int slave(int i)
{
    srand(i);
    char buf[512]={0};
    char buf_read[512]={0};
    snprintf(buf,sizeof(buf),str,i,rand()%10);
    printf("进入slave函数\n");
    while(1)
    {

        sleep(i);
        int size = write(socketPair[i].socketfd[0], buf, strlen(buf));
        printf("write size is %d,i is %d\n",size,i);
        size = read(socketPair[i].socketfd[0], buf_read, sizeof(buf_read));
        if(size <=0)
        {
            printf("errno is %d,%s\n",errno,strerror(errno));
        }else
        {
            printf("buf_read from master is %s,i is %d\n",buf_read,i);
        }

    }
    printf("离开slave函数\n");
    return 0;
}
