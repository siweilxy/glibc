//
// Created by siwei on 19-5-4.
//

#include "common.h"
#include <sys/resource.h>

//struct rusage
//{
//    /* Total amount of user time used.  */
//    struct timeval ru_utime;
//    /* Total amount of system time used.  */
//    struct timeval ru_stime;
//    /* Maximum resident set size (in kilobytes).  */
//    __extension__ union
//    {
//        long int ru_maxrss;
//        __syscall_slong_t __ru_maxrss_word;
//    };
//    /* Amount of sharing of text segment memory
//       with other processes (kilobyte-seconds).  */
//    /* Maximum resident set size (in kilobytes).  */
//    __extension__ union
//    {
//        long int ru_ixrss;
//        __syscall_slong_t __ru_ixrss_word;
//    };
//    /* Amount of data segment memory used (kilobyte-seconds).  */
//    __extension__ union
//    {
//        long int ru_idrss;
//        __syscall_slong_t __ru_idrss_word;
//    };
//    /* Amount of stack memory used (kilobyte-seconds).  */
//    __extension__ union
//    {
//        long int ru_isrss;
//        __syscall_slong_t __ru_isrss_word;
//    };
//    /* Number of soft page faults (i.e. those serviced by reclaiming
//       a page from the list of pages awaiting reallocation.  */
//    __extension__ union
//    {
//        long int ru_minflt;
//        __syscall_slong_t __ru_minflt_word;
//    };
//    /* Number of hard page faults (i.e. those that required I/O).  */
//    __extension__ union
//    {
//        long int ru_majflt;
//        __syscall_slong_t __ru_majflt_word;
//    };
//    /* Number of times a process was swapped out of physical memory.  */
//    __extension__ union
//    {
//        long int ru_nswap;
//        __syscall_slong_t __ru_nswap_word;
//    };
//    /* Number of input operations via the file system.  Note: This
//       and `ru_oublock' do not include operations with the cache.  */
//    __extension__ union
//    {
//        long int ru_inblock;
//        __syscall_slong_t __ru_inblock_word;
//    };
//    /* Number of output operations via the file system.  */
//    __extension__ union
//    {
//        long int ru_oublock;
//        __syscall_slong_t __ru_oublock_word;
//    };
//    /* Number of IPC messages sent.  */
//    __extension__ union
//    {
//        long int ru_msgsnd;
//        __syscall_slong_t __ru_msgsnd_word;
//    };
//    /* Number of IPC messages received.  */
//    __extension__ union
//    {
//        long int ru_msgrcv;
//        __syscall_slong_t __ru_msgrcv_word;
//    };
//    /* Number of signals delivered.  */
//    __extension__ union
//    {
//        long int ru_nsignals;
//        __syscall_slong_t __ru_nsignals_word;
//    };
//    /* Number of voluntary context switches, i.e. because the process
//       gave up the process before it had to (usually to wait for some
//       resource to be available).  */
//    __extension__ union
//    {
//        long int ru_nvcsw;
//        __syscall_slong_t __ru_nvcsw_word;
//    };
//    /* Number of involuntary context switches, i.e. a higher priority process
//       became runnable or the current process used up its time slice.  */
//    __extension__ union
//    {
//        long int ru_nivcsw;
//        __syscall_slong_t __ru_nivcsw_word;
//    };
//};

int test_getrusage()
{
    pstart
    int who = RUSAGE_SELF;
    struct rusage usage;
    int ret;
    ret = getrusage(who,&usage);
    printf("%lu\n",usage.ru_msgsnd);
    pend
    return 0;
}

///* Kinds of resource limit.  */
//enum __rlimit_resource
//{
//    /* Per-process CPU limit, in seconds.  */
//    RLIMIT_CPU = 0,
//#define RLIMIT_CPU RLIMIT_CPU
//
//    /* Largest file that can be created, in bytes.  */
//    RLIMIT_FSIZE = 1,
//#define	RLIMIT_FSIZE RLIMIT_FSIZE
//
//    /* Maximum size of data segment, in bytes.  */
//    RLIMIT_DATA = 2,
//#define	RLIMIT_DATA RLIMIT_DATA
//
//    /* Maximum size of stack segment, in bytes.  */
//    RLIMIT_STACK = 3,
//#define	RLIMIT_STACK RLIMIT_STACK
//
//    /* Largest core file that can be created, in bytes.  */
//    RLIMIT_CORE = 4,
//#define	RLIMIT_CORE RLIMIT_CORE
//
//    /* Largest resident set size, in bytes.
//       This affects swapping; processes that are exceeding their
//       resident set size will be more likely to have physical memory
//       taken from them.  */
//            __RLIMIT_RSS = 5,
//#define	RLIMIT_RSS __RLIMIT_RSS
//
//    /* Number of open files.  */
//    RLIMIT_NOFILE = 7,
//    __RLIMIT_OFILE = RLIMIT_NOFILE, /* BSD name for same.  */
//#define RLIMIT_NOFILE RLIMIT_NOFILE
//#define RLIMIT_OFILE __RLIMIT_OFILE
//
//    /* Address space limit.  */
//    RLIMIT_AS = 9,
//#define RLIMIT_AS RLIMIT_AS
//
//    /* Number of processes.  */
//            __RLIMIT_NPROC = 6,
//#define RLIMIT_NPROC __RLIMIT_NPROC
//
//    /* Locked-in-memory address space.  */
//            __RLIMIT_MEMLOCK = 8,
//#define RLIMIT_MEMLOCK __RLIMIT_MEMLOCK
//
//    /* Maximum number of file locks.  */
//            __RLIMIT_LOCKS = 10,
//#define RLIMIT_LOCKS __RLIMIT_LOCKS
//
//    /* Maximum number of pending signals.  */
//            __RLIMIT_SIGPENDING = 11,
//#define RLIMIT_SIGPENDING __RLIMIT_SIGPENDING
//
//    /* Maximum bytes in POSIX message queues.  */
//            __RLIMIT_MSGQUEUE = 12,
//#define RLIMIT_MSGQUEUE __RLIMIT_MSGQUEUE
//
//    /* Maximum nice priority allowed to raise to.
//       Nice levels 19 .. -20 correspond to 0 .. 39
//       values of this resource limit.  */
//            __RLIMIT_NICE = 13,
//#define RLIMIT_NICE __RLIMIT_NICE
//
//    /* Maximum realtime priority allowed for non-priviledged
//       processes.  */
//            __RLIMIT_RTPRIO = 14,
//#define RLIMIT_RTPRIO __RLIMIT_RTPRIO
//
//    /* Maximum CPU time in µs that a process scheduled under a real-time
//       scheduling policy may consume without making a blocking system
//       call before being forcibly descheduled.  */
//            __RLIMIT_RTTIME = 15,
//#define RLIMIT_RTTIME __RLIMIT_RTTIME
//
//    __RLIMIT_NLIMITS = 16,
//    __RLIM_NLIMITS = __RLIMIT_NLIMITS
//#define RLIMIT_NLIMITS __RLIMIT_NLIMITS
//#define RLIM_NLIMITS __RLIM_NLIMITS
//};

int test_getrlimit()
{
    pstart
    struct rlimit limit;
    int resource = RLIMIT_CPU;
    int ret = 0;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("1.RLIMIT_CPU:最大允许的CPU使用时间，秒为单位。当进程达到软限制，内核将给其发送SIGXCPU信号，这一信号的默认行为是终止进程的执行。然而，可以捕捉信号，处理句柄可将控制返回给主程序。如果进程继续耗费CPU时间，核心会以每秒一次的频率给其发送SIGXCPU信号，直到达到硬限制，那时将给进程发送 SIGKILL信号终止其执行\n");
    printf("RLIMIT_CPU rlim_max info is %lu second,rlim_cur is %lusecond to years is %lu\n\n",limit.rlim_max,limit.rlim_cur,limit.rlim_cur/60/60/24/30/365);


    resource = RLIMIT_FSIZE;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("2.RLIMIT_FSIZE:进程可建立的文件的最大长度。如果进程试图超出这一限制时，核心会给其发送SIGXFSZ信号，默认情况下将终止进程的执行\n");
    printf("RLIMIT_FSIZE is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);


    resource = RLIMIT_DATA;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("3.RLIMIT_DATA:the max size of data memory for the process,if the process tries to allocate data memory beyond this amount,the allocation functions fails\n");
    printf("RLIMIT_DATA is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);


    resource = RLIMIT_STACK;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("3.RLIMIT_STACK:the max stack size for the process,if the process tries to extend its stackpast this size it gets a SIGSEGV signal\n");
    printf("RLIMIT_STACK is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);


    resource = RLIMIT_CORE;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("4.RLIMIT_CORE:the max size coee file that this process can create.if process terminates and would dump a core file lager than this,then no core file is created.so setting this limit to zero prevents core files from ever being created\n");
    printf("RLIMIT_CORE is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);


    resource = RLIMIT_RSS;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("5.RLIMIT_RSS:The max amount of physical memory that this processs should get,this parameter is a guide for the system's scheduler and memory allocator,the system may give the process more memory when there is a surplus\n");
    printf("RLIMIT_RSS is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);


    resource = RLIMIT_MEMLOCK;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("6.RLIMIT_MEMLOCK:The max amount of  memory that can be locked into physical memory so it will never be paged out\n");
    printf("RLIMIT_MEMLOCK is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);


    resource = RLIMIT_NPROC;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("7.RLIMIT_NPROC:The max number of process that can be created with the same user id,if you have reached the limit for your user ID,ford will fail with EAGAIN\n");
    printf("RLIMIT_NPROC is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);


    resource = RLIMIT_NOFILE;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("8.RLIMIT_NOFILE and RLIMIT_OFILE:The max number of files that process can open,if it tries to open more files than this,its open attempt fails with errno EMFILE\n");
    printf("RLIMIT_NOFILE is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);

    resource = RLIMIT_AS;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("9.RLIMIT_AS:The max size of total memory that this process should get,if the process tries to allocate more memory beyond this amount with,for example:brk,malloc,mmap or sbrk,the allocation function fails\n");
    printf("RLIMIT_AS is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);


    resource = RLIM_NLIMITS;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("10.RLIM_NLIMITS:The number of different resource limits.any valid resource operand must be less than RLIM_NLIMITS\n");
    printf("RLIM_NLIMITS is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);

    resource = RLIMIT_LOCKS;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("11.RLIMIT_LOCKS:Maximum number of file locks 进程可建立的锁的最大值\n");
    printf("RLIMIT_LOCKS is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);

    resource = RLIMIT_SIGPENDING;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("12.RLIMIT_SIGPENDING: Maximum number of pending signals.\n");
    printf("RLIMIT_SIGPENDING is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);

    resource = RLIMIT_MSGQUEUE;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("13.RLIMIT_MSGQUEUE: Maximum bytes in POSIX message queues\n");
    printf("RLIMIT_MSGQUEUE is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);

    resource = RLIMIT_NICE;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("14.RLIMIT_NICE: Maximum nice priority allowed to raise to. Nice levels 19 .. -20 correspond to 0 .. 39 values of this resource limit.  \n");
    printf("RLIMIT_NICE is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);

    resource = RLIMIT_RTPRIO;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("15.RLIMIT_RTPRIO: Maximum realtime priority allowed for non-priviledged processes.\n");
    printf("RLIMIT_RTPRIO is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);

    resource = RLIMIT_RTTIME;
    ret = getrlimit(resource,&limit);
    if(ret != 0)
    {
        printf("!!!!!!!!!!!!error!!!!!!!");
    }
    printf("resource now is %d\n",resource);
    printf("16.RLIMIT_RTTIME: Maximum CPU time in µs that a process scheduled under a real-time\n"
                   "     scheduling policy may consume without making a blocking system\n"
                   "     call before being forcibly descheduled.");
    printf("RLIMIT_RTTIME is %lu max is %lu\n\n",limit.rlim_cur,limit.rlim_max);

    pend
    return 0;
}
