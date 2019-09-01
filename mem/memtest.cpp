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
    std::cout<<"从上面可以看出内存对齐后指针的地址就变了，初始化一块内存，地址是对齐地址的整数倍"<<std::endl;
    /*The aligned_alloc function allocates a block of size bytes whose address is a multiple
    of alignment. The alignment must be a power of two and size must be a multiple of
    alignment.
    The aligned_alloc function returns a null pointer on error and sets errno to one of
    the following values:
    ENOMEM
    There was insufficient memory available to satisfy the request.Chapter 3: Virtual Memory Allocation And Paging
    EINVAL
    50
    alignment is not a power of two.
    This function was introduced in ISO C11 and hence may have better
    portability to modern non-POSIX systems than posix_memalign.*/
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
    std::cout<<"memalign已经被aligned_alloc取代"<<std::endl;
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
    return 0;
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

int test_realloc()
{//realloc只能扩大，不能缩小
    char test[10]="123456789";
    char test1[15]="1234567890123";
    std::cout<<"测试realloc，修改申请内存的大小"<<std::endl;
    char* t = (char*)malloc(10);
    memcpy(t,&test[0],10);
    std::cout<<"test is:"<<t<<std::endl;
    std::cout<<"使用realloc修改内存大小"<<std::endl;
    void *value = realloc(t,15);
    memcpy(value,&test1[0],sizeof(test1));
    std::cout<<"使用realloc修改后： "<<(char*)value<<std::endl;
    return 0;
}

