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
} test_t;

typedef struct socketFd_s
{
    int socketfd[2];
    int pid;
} socketFd_t;

typedef struct msg_s
{
    int id;
    int pid;
    int result;
    int order;
} msg_t;

enum orderType
{
    order_start = 0, order_end
};

enum orderResult
{
    order_success = 0, order_failed
};

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
int test_mprobe();
int test_pipe();
int testSocketsInterface();
int test_sysconf();
int test_backtrace();
int masterAndSlave();
int slave(int i);
int master();
int master_nonblock();
void setnonblcokingmode(int fd);

#define NONE                 "\e[0m"
#define BLACK                "\e[0;30m"
#define L_BLACK              "\e[1;30m"
#define RED                  "\e[0;31m"
#define L_RED                "\e[1;31m"
#define GREEN                "\e[0;32m"
#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"
#define BLUE                 "\e[0;34m"
#define L_BLUE               "\e[1;34m"
#define PURPLE               "\e[0;35m"
#define L_PURPLE             "\e[1;35m"
#define CYAN                 "\e[0;36m"
#define L_CYAN               "\e[1;36m"
#define GRAY                 "\e[0;37m"
#define WHITE                "\e[1;37m"

#define BOLD                 "\e[1m"
#define UNDERLINE            "\e[4m"
#define BLINK                "\e[5m"
#define REVERSE              "\e[7m"
#define HIDE                 "\e[8m"
#define CLEAR                "\e[2J"
#define CLRLINE              "\r\e[K"
