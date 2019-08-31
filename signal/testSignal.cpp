//
// Created by siwei on 19-5-18.
//

#include <signal.h>
#include <iostream>
#include <execinfo.h>
#include "common.h"
void signal_handler_fun(int signal_num)
{
    pstart
    std::cout<<"1/0 error"<<std::endl;
    pend

    int size =16;
    void* array[16];
    int stack_nm = backtrace(array,size);
    char ** stacktrace = backtrace_symbols(array,stack_nm);
    for (int i = 0; i < stack_nm; ++i) {
        std::cout<<stacktrace[i]<<std::endl;
    }
    free(stacktrace);
    raise(SIGQUIT);
    exit(0);
}

int testSignal()
{
    pstart
    sighandler_t p = signal_handler_fun;
    signal(SIGFPE,p);
    //signal(SIGINT,SIG_IGN);
    //for (;;);
    int j = 1/0;
    pend
    return 0;
}
