/*
 * recv.cpp
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

#define BUF_SIZE 1024
#define FIFO_NAME "testfifo"

int main(int argc, char* argv[])
{
    int fd;
    char buf[BUF_SIZE];

    fd = open(FIFO_NAME, O_RDONLY);

    read(fd, buf, BUF_SIZE);

    printf("收到數據%s\n", buf);

    close(fd);

    return 0;
}
