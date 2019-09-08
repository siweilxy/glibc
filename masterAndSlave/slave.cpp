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
char str[] = "slave%d_rand_%d";

int slave(int i)
{
    srand(i);
    char buf[512] =
    { 0 };
    char buf_read[512] =
    { 0 };
    msg_t* msg = NULL;
    snprintf(buf, sizeof(buf), str, i, rand() % 10);
    printf("进入slave%d 函数\n",i);
    int size = 0;
    while (1)
    {
        size = read(socketPair[i].socketfd[0], buf_read, sizeof(buf_read));
        if (size <= 0)
        {
            printf("errno is %d,%s\n", errno, strerror(errno));
        } else
        {
            msg = (msg_t*) buf_read;
            switch (msg->order)
            {
            case order_start:
            {
                printf("%d:%d收到开始指令\n",i,getpid());

                //sleep(i);
                msg->id = i;
                msg->pid = getpid();
                msg->result = order_success;
                memcpy(buf, msg, sizeof(msg_t));
                int size = write(socketPair[i].socketfd[0], buf, sizeof(msg_t));
                printf("%d发送结果应答完毕\n",i);
                break;
            }
            case order_end:
            {
                printf("%d %d 收到停止指令\n",i,getpid());
                exit(0);
                break;
            }
            default:
                printf("error order\n");
            }
        }

    }
    printf("离开slave函数\n");
    return 0;
}
