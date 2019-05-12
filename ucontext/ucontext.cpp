//
// Created by siwei on 19-5-13.
//

#include <stdio.h>
#include <ucontext.h>
#include <common.h>

void test_ucontext(void* arg);

void func11()
{
    start
    end
}

void func21()
{
    start
    end
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

void test_ucontext()
{
    context_test();
}