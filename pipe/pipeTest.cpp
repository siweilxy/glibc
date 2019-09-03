/*
 * pipeTest.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: siwei
 */

#include <cstdlib>
#include <iostream>
#include <malloc.h>
#include <vector>
#include <cstring>
#include <mcheck.h>
#include <zconf.h>
#include "common.h"
#include <errno.h>

void read_from_pipe(int file)
{
    pstart
    FILE *stream;
    char msg[100]={0};

    while(1)
    {
        memset(msg,0,100);
        ssize_t s = read(file, msg, sizeof(msg));
        std::cout<<"pid:"<<getpid()<<" "<<msg<<"."<<std::endl;
        if(msg[0] == 'Q'||msg[0]== 'q')
        {
            std::cout<<"read end.msg is "<<msg<<std::endl;
            break;
        }
    }
    pend
}
/* Write some random text to the pipe. */
void write_to_pipe(int file)
{
    pstart
    FILE *stream;
    char temp[10]={0};
    char temHello[]="hello, world!\n";
    char temBye[]="goodbye, world!\n";
    char buf[512]={0};
    memcpy(buf,temHello,sizeof(temHello));
    write(file,&buf[0],15);

    while(1)
    {
        std::cout<<"请输入字符串：\n"<<std::endl;
        std::cin>>temp;
        std::cout<<"输入的字符串为："<<temp<<std::endl;
        write(file,&temp[0],strlen(temp));
        if(temp[0] == 'Q'||temp[0] == 'q')
        {
            break;
        }
    }

    write(file,&temBye[0],strlen(temBye));
    pend
}

int test_pipe()
{
    pid_t pid;
    int mypipe[2];
    /* Create the pipe. */
    if (pipe(mypipe))
    {
        fprintf(stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }
    /* Create the child process. */
    pid = fork();
    if (pid == (pid_t) 0)
    {
        std::cout<<"child pid is "<<getpid()<<std::endl;
        /* This is the child process.
         Close other end first. */
        close(mypipe[1]);
        read_from_pipe(mypipe[0]);
        //exit(0);
        return -1;
    } else if (pid < (pid_t) 0)
    {
        /* The fork failed. */
        fprintf(stderr, "Fork failed.\n");
        return -1;
    } else
    {
        std::cout<<"parent pid is "<<getpid()<<std::endl;
        /* This is the parent process.
         Close other end first. */
        close(mypipe[0]);
        write_to_pipe(mypipe[1]);
        return 0;
    }

    return 0;
}
