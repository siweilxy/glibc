/*
 * send.cpp
 *
 *  Created on: Sep 4, 2019
 *      Author: siwei
 */

#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "testfifo"

int main(int argc, char* argv[])
{
    int fd;
    char buf[] = "yyyyyyy";

    mkfifo(FIFO_NAME, S_IFIFO | 0666);

    fd = open(FIFO_NAME, O_WRONLY);

    write(fd, buf, strlen(buf) + 1);

    close(fd);

    unlink(FIFO_NAME); //删除管道文件

    //sleep(1);
    printf("发送完毕\n");
    return 0;
}
