//
// Created by siwei on 19-4-7.
//

#ifndef GLIBC_COMMON_H
#define GLIBC_COMMON_H

#endif //GLIBC_COMMON_H

#include <iostream>

typedef struct test_s
{
    int i;
    int j;
    char data[1024];
}test_t;

#define pstart std::cout<<__FUNCTION__<<" ====================start====================="<<std::endl;
#define pend std::cout<<__FUNCTION__<<" ======================end======================="<<std::endl;

int print_info();
int test_aligned_alloc();
int test_memalign();
int test_mallopt_M_PERTURB();
int test_mallopt_M_MMAP_THRESHOLD();
int test_mallopt_M_TRIM_THRESHOLD();
int test_mtrace();
int test_brk_sbrk();
int test_mmap();
int test_getrusage();
int test_getrlimit();
int testSetJmp();
int test_ucontext();
int testSignal();
int test_realloc();
int test_mallopt_M_MAP_MAX();
int test_mcheck();
