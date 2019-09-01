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
#include <errno.h>


void abortfun(enum mcheck_status mstatus)
{
    std::cout<<"内存申请或者释放出现错误 "<<mstatus<<std::endl;
}

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

    for (int j = 0; j < numbers; ++j) {
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

int test_mallopt_M_MAP_MAX()
{
    pstart
    print_info();
    mallopt(M_MMAP_MAX,0);
    int *t;
    t = (int *)malloc(sizeof(int));
    mallopt(M_PERTURB,1);
    std::cout<<"t is "<<*t<<std::endl;
    std::cout<<"M_MMAP_MAX 设置的是mmap初始化的内存块数的最大值，如果是0,则表示不使用mmap进行初始化，默认值是65536,这个值也可以通过"
            "MALLOC_MMAP_MAX_ 环境变量来初始化"<<std::endl;
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
//    All chunks larger than this value are allocated outside the normal heap,
//using the mmap system call. This way it is guaranteed that the memory for
//these chunks can be returned to the system on free. Note that requests
//smaller than this threshold might still be allocated via mmap.
//If this parameter is not set, the default value is set as 128 KiB and the
//threshold is adjusted dynamically to suit the allocation patterns of the
//program. If the parameter is set, the dynamic adjustment is disabled and
//the value is set statically to the input value.
//This parameter can also be set for the process at startup by setting the
//environment variable MALLOC_MMAP_THRESHOLD_ to the desired value.

    pstart
    std::cout<<"比 M_MMAP_THRESHOLD 值大的内存块会被用mmap系统调用在初始化在一般堆外，这些内存块可以被用free函数释放，注意比这个值小的内存块也有可能会被使用mmap来申请内存，这个值也可以通过环境变量用MALLOC_MMAP_THRESHOLD_来设置"<<std::endl;
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

int test_mcheck()
{
    pstart
    std::cout<<"调用该函数后，后续的内存分配、释放都将进行内存的连续性检查，并在内存连续性检查失败后，"
            "调用 abortfunc函数，如果abortfunc使用NULL，则使用默认行为：打印错误信息并调用abort()退出"<<std::endl;
    int ret = mcheck(abortfun);
    if (ret != 0)  // 注册 mcheck 内存检查功能
    {
            std::cout<<"mcheck error :"<< strerror(errno)<< " ret is "<<ret<<std::endl;;
            return -1;
    }
    char *p = NULL;

    p = (char*)malloc(10);

    free(p);
    printf("1st free finished.\n");

    free(p); // 第二次，p 指向的内存已经被释放，会被检查到，将会调用 \abortfunc

    printf("2nd free\n");

    pend
    return 0;
}

