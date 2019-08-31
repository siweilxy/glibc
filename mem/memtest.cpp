//
// Created by siwei on 19-4-7.
//



#include <cstdlib>
#include <iostream>
#include <malloc.h>
#include <vector>
#include <cstring>
#include <mcheck.h>
#include <zconf.h>
#include "common.h"

int mallocAndFree(int mallocLength,int numbers)
{
    char *p = nullptr;
    void* ps[numbers];
    for (unsigned int i = 0; i < numbers; ++i) {
        //std::cout<<"s is "<<s.c_str()<<std::endl;
        p = (char*)malloc(mallocLength);
        memset(p,0, mallocLength);
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


    for (int j = 0; j < numbers; ++j) {
        //std::cout<<ps[j]<<std::endl;
        free(ps[j]);
    }
    std::cout<<"after free"<<std::endl;
    print_info();
    return 0;
}

int test_aligned_alloc()
{
    pstart
    print_info();
    test_t *t1,*t2,*t3;
    t1  = (test_t*)malloc(1024);
    t2 = (test_t*)aligned_alloc(123456, sizeof(test_t)*1024);
    std::cout<<"t1: "<<t1<<" t2: "<<t2<<" errno is "<<errno<<std::endl;
    pend
    return 0;
}

int test_memalign()
{
    pstart
    print_info();
    test_t *t1,*t2,*t3;
    t1  = (test_t*)malloc(1024);
    t2 = (test_t*)memalign(123456, sizeof(test_t)*1024);
    std::cout<<"t1: "<<t1<<" t2: "<<t2<<" errno is "<<errno<<std::endl;
    pend
    return 0;
}

int test_mallopt_M_PERTURB()
{
    pstart
    print_info();
    mallopt(M_PERTURB,0);
    int *t;
    t = (int *)malloc(sizeof(int));
    mallopt(M_PERTURB,1);
    std::cout<<"t is "<<*t<<std::endl;
    pend
}

int test_mallopt_M_MMAP_THRESHOLD()
{
    pstart
    mallopt(M_MMAP_THRESHOLD,0);
    mallocAndFree(1024,100);
    pend
    return 0;
}

int test_mallopt_M_TRIM_THRESHOLD()
{
    pstart
    mallopt(M_MMAP_THRESHOLD,1024*400);
    //mallopt(M_TRIM_THRESHOLD,0);
    mallocAndFree(1024*100,1000);
    pend
    return 0;
}

int test_mtrace()
{
    pstart
    mtrace();
    //mallocAndFree(10,10);
    malloc(100);
    pend
    return 0;
}

int test_brk_sbrk()
{
    pstart
    void *brk_end = nullptr;
    void *p = sbrk(0);
    printf("current brk end:%p\n",p);
    brk(p+4096);
    brk_end = sbrk(0);
    printf("current brk end:%p\n",brk_end);
    pend
    return 0;
}

int test_mmap()
{
    pstart

    pend
    return 0;
}

