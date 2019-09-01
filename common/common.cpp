//
// Created by siwei on 19-5-2.
//
#include <malloc.h>

//printf("struct mallinfo\n"
//"{\n"
//"int arena;    /* non-mmapped space allocated from system */\n"
//"int ordblks;  /* number of free chunks */\n"
//"int smblks;   /* number of fastbin blocks */\n"
//"int hblks;    /* number of mmapped regions */\n"
//"int hblkhd;   /* space in mmapped regions */\n"
//"int usmblks;  /* maximum total allocated space */\n"
//"int fsmblks;  /* space available in freed fastbin blocks */\n"
//"int uordblks; /* total allocated space */\n"
//"int fordblks; /* total free space */\n"
//"int keepcost; /* top-most, releasable (via malloc_trim) space */\n"
//"};");

int print_info()
{
    struct mallinfo mi = mallinfo();
    printf("count by mallinfo:\n");
    printf("mi.arena:    %d,     malloc中使用sbrk初始化获得的内存总大小 total size of memery allocated with sbrk by malloc\n", mi.arena);
    printf("mi.ordblks:  %d,     被释放的内存数 number of chunks not in use,the memory allocator internally "
                   "gets chunks of memory from the system,and then carves them up to "
                   "satisfy individual malloc requests\n",mi.ordblks);
    printf("mi.hblks:    %d,     mmap初始化的总块数total number of chunks allocated with mmap\n",mi.hblks);
    printf("mi.hblkhd:   %d,     mmap初始化的总大小total size of memory allocated with mmap,in bytes\n",mi.hblkhd);
    printf("mi.uordblks: %d,     初始化内存的总大小the total size of memory occupied by chunks handed out by malloc\n",mi.uordblks);
    printf("mi.fordblks: %d,     被释放内存的总大小the total size of memory occupied by free (not in use) chunks\n",mi.fordblks);
    printf("mi.keepcost: %d,     最顶部，可释放的内存？比如通过 malloc_trim释放，this is the size of the top-most releaseable chunk that normally borders the end of the heap\n",
           mi.keepcost);
    printf("from malloc_stats:\n");
    malloc_stats();
    printf("\n");
    return 0;
}
