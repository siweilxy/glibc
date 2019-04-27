//
// Created by siwei on 19-4-7.
//



#include <cstdlib>
#include <iostream>
#include <malloc.h>
#include <zconf.h>
#include <vector>
#include <cstdlib>
#include <cstring>
#include "common.h"

#define funcLog std::cout<<__FUNCTION__<<" start"<<std::endl;


void test_aligned_alloc()
{
    funcLog
    test_t *t1,*t2,*t3;
    t1  = (test_t*)malloc(1024);
    t2 = (test_t*)aligned_alloc(123456, sizeof(test_t)*1024);
    std::cout<<"t1: "<<t1<<" t2: "<<t2<<" errno is "<<errno<<std::endl;
}

void test_memalign()
{
    funcLog
    test_t *t1,*t2,*t3;
    t1  = (test_t*)malloc(1024);
    t2 = (test_t*)memalign(123456, sizeof(test_t)*1024);
    std::cout<<"t1: "<<t1<<" t2: "<<t2<<" errno is "<<errno<<std::endl;
}

void test_mallopt_M_PERTURB()
{
    funcLog
    mallopt(M_PERTURB,0);
    int *t;
    t = (int *)malloc(sizeof(int));
    mallopt(M_PERTURB,1);
    std::cout<<"t is "<<*t<<std::endl;
}

void test_mallopt_M_MMAP_THRESHOLD()
{
    funcLog
    mallopt(M_MMAP_THRESHOLD,0);
    char *p = nullptr;
    std::vector<std::string> ps;
    //std::vector<void*> pt;
    //void* ps[1000000];
    std::string a = "1234567890";
    for (unsigned int i = 0; i < 100000; ++i) {
        a = a + std::to_string(i);
        //p = (char*)malloc(sizeof(a));
        //memcpy(p,a, sizeof(a));
//        if(p == NULL)
//        {
//            printf("malloc error");
//        }
        ps.push_back(a);
    }

    printf("push end,size is %d\n", ps.size());
    char t[111];
    while (1){
        gets(t);
        if (strcmp(t,"end") == 0)
        {
            printf("end\n");
            break;
        }
    }

    ps.clear();

//    for (int j = 0; j < 1000000; ++j) {
//        free(ps[j]);
//    }

    while (1){
        gets(t);
        if (strcmp(t,"end") == 0)
        {
            printf("end\n");
            break;
        }
    }

}

void test_mallopt_M_TRIM_THRESHOLD()
{
    funcLog
    mallopt(M_TRIM_THRESHOLD,10);
    char *p = nullptr;
    std::vector<std::string> ps;
    //std::vector<void*> pt;
    //void* ps[1000000];
    std::string a = "1234567890";
    for (unsigned int i = 0; i < 100000; ++i) {
        a = a + std::to_string(i);
        //p = (char*)malloc(sizeof(a));
        //memcpy(p,a, sizeof(a));
//        if(p == NULL)
//        {
//            printf("malloc error");
//        }
        ps.push_back(a);
    }

    printf("push end,size is %d\n", ps.size());
    char t[111];
    while (1){
        gets(t);
        if (strcmp(t,"end") == 0)
        {
            printf("end\n");
            break;
        }
    }

    ps.clear();

//    for (int j = 0; j < 1000000; ++j) {
//        free(ps[j]);
//    }

    while (1){
        gets(t);
        if (strcmp(t,"end") == 0)
        {
            printf("end\n");
            break;
        }
    }

}