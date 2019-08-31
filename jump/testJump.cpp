//
// Created by siwei on 19-5-12.
//

#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <common.h>

jmp_buf main_loop;
int ret = 0;
int do_command();

int abort_to_main_loop(int status)
{
    pstart
    longjmp(main_loop,status);
    pend
    return 0;
}

int func1()
{
    pstart
    pend
    return 0;
}

int testSetJmp()
{
    pstart
    int j = 0;
    while(1)
    {
        std::cout<<"befor setjmp"<<std::endl;
        ret = setjmp(main_loop);
        std::cout<<"after setjmp"<<std::endl;
        int i = 0;
        if (ret){
            std::cout<<"ret is"<<ret<<"save end i is "<<i++<<" j is "<<j++<<std::endl;
            std::cout<<"back to func,ret is not 0"<<std::endl;
            func1();

        } else
        {
            std::cout<<"ret is"<<ret<<"save end i is "<<i++<<" j is "<<j++<<std::endl;
            std::cout<<"first setjmp ret is 0"<<std::endl;
            do_command();
        }
    }
    pend
    return 0;
}

int do_command()
{
    pstart
    char buffer[128];
    fgets(buffer,128,stdin);
    std::cout<<buffer<<std::endl;
    abort_to_main_loop(0);

    pend
    return 0;
}
