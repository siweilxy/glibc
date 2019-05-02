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

void print_info()
{
    struct mallinfo mi = mallinfo();
    printf("count by mallinfo:\n");
    printf("mi.arena:    %d,     total size of memery allocated with sbrk by malloc\n", mi.arena);
    printf("mi.ordblks:  %d,     number of chunks not in use,the memory allocator internally "
                   "gets chunks of memory from the system,and then carves them up to "
                   "satisfy individual malloc requests\n",mi.ordblks);
    printf("mi.hblks:    %d,     total number of chunks allocated with mmap\n",mi.hblks);
    printf("mi.hblkhd:   %d,     total size of memory allocated with mmap,in bytes\n",mi.hblkhd);
    printf("mi.uordblks: %d,     the total size of memory occupied by chunks handed out by malloc\n",mi.uordblks);
    printf("mi.fordblks: %d,     the total size of memory occupied by free (not in use) chunks\n",mi.fordblks);
    printf("mi.keepcost: %d,     this is the size of the top-most releaseable chunk that normally borders the end of the heap\n",
           mi.keepcost);
    printf("from malloc_stats:\n");
    malloc_stats();
    printf("\n");
}