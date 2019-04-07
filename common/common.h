//
// Created by siwei on 19-4-7.
//

#ifndef GLIBC_COMMON_H
#define GLIBC_COMMON_H

#endif //GLIBC_COMMON_H

typedef struct test_s
{
    int i;
    int j;
    char data[1024];
}test_t;

void test_aligned_alloc();
void test_memalign();
void test_mallopt();
