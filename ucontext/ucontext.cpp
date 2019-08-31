//
// Created by siwei on 19-5-13.
//

#include <stdio.h>
#include <ucontext.h>
#include <common.h>

int test_ucontext(void* arg);

void func11()
{
    pstart
    pend
}

void func21()
{
    pstart
    pend
}

void context_test()
{
    char stack[1024*128];
    ucontext_t child,main;
    getcontext(&child);
    child.uc_stack.ss_sp = stack;
    child.uc_stack.ss_size = sizeof(stack);
    child.uc_stack.ss_flags = 0;
    child.uc_link = &main;

    makecontext(&child,func11,0);
    swapcontext(&main,&child);
    std::cout<<"main"<<std::endl;
}

int test_ucontext()
{
    context_test();
    return 0;
}
