//
// Created by siwei on 19-4-7.
//



#include <cstdlib>
#include <iostream>
#include <malloc.h>
#include <vector>
#include <cstring>
#include "common.h"

#define start std::cout<<__FUNCTION__<<" start"<<std::endl;
#define end std::cout<<__FUNCTION__<<" end"<<std::endl;

void mallocAndFree()
{
    char *p = nullptr;
    void* ps[10000];
    for (unsigned int i = 0; i < 10000; ++i) {
        //std::cout<<"s is "<<s.c_str()<<std::endl;
        p = (char*)malloc(1000*900);
        memset(p,0, 1000*900);
        if(p == NULL)
        {
            printf("malloc error");
        }
        ps[i] = p;
    }

    std::cout<<"after malloc"<<std::endl;
    print_info();

    char t[111];
    while (1){
        fgets(t,4,stdin);
        if (strcmp(t,"end") == 0)
        {
            printf("end\n");
            break;
        }
    }


    for (int j = 0; j < 10000; ++j) {
        //std::cout<<ps[j]<<std::endl;
        free(ps[j]);
    }
    std::cout<<"after free"<<std::endl;
    print_info();
}

void test_aligned_alloc()
{
    start
    print_info();
    test_t *t1,*t2,*t3;
    t1  = (test_t*)malloc(1024);
    t2 = (test_t*)aligned_alloc(123456, sizeof(test_t)*1024);
    std::cout<<"t1: "<<t1<<" t2: "<<t2<<" errno is "<<errno<<std::endl;
    end
}

void test_memalign()
{
    start
    print_info();
    test_t *t1,*t2,*t3;
    t1  = (test_t*)malloc(1024);
    t2 = (test_t*)memalign(123456, sizeof(test_t)*1024);
    std::cout<<"t1: "<<t1<<" t2: "<<t2<<" errno is "<<errno<<std::endl;
    end
}

void test_mallopt_M_PERTURB()
{
    start
    print_info();
    mallopt(M_PERTURB,0);
    int *t;
    t = (int *)malloc(sizeof(int));
    mallopt(M_PERTURB,1);
    std::cout<<"t is "<<*t<<std::endl;
    end
}

void test_mallopt_M_MMAP_THRESHOLD()
{
    start
    mallopt(M_MMAP_THRESHOLD,0);
    mallocAndFree();
    end
}

void test_mallopt_M_TRIM_THRESHOLD()
{
    start
    mallopt(M_TRIM_THRESHOLD,0);
    mallocAndFree();
    end
}