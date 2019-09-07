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

extern socketFd_t socketPair[512];
char str[]="slave%d_rand_%d";

int slave(int i)
{
    srand(i);
    char buf[512]={0};
    snprintf(buf,sizeof(buf),str,i,rand()%10);
    printf("进入slave函数\n");
    while(1)
    {

        sleep(i);
        int size = write(socketPair[i].socketfd[0], buf, strlen(buf));
        //printf("write size is %d,i is %d\n",size,i);
    }
    printf("离开slave函数\n");
    return 0;
}
