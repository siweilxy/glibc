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
void do_command();

void abort_to_main_loop(int status)
{
    start
    longjmp(main_loop,status);
    end
}

void func1()
{
    start
    end
}

void testSetJmp()
{
    start
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
    end
}

void do_command()
{
    start
    char buffer[128];
    fgets(buffer,128,stdin);
    std::cout<<buffer<<std::endl;
    abort_to_main_loop(0);

    end
}