#include <iostream>
#include <cstring>
#include "common.h"

int main() {
    printf("struct mallinfo\n"
                   "{\n"
                   "int arena;    /* non-mmapped space allocated from system */\n"
                   "int ordblks;  /* number of free chunks */\n"
                   "int smblks;   /* number of fastbin blocks */\n"
                   "int hblks;    /* number of mmapped regions */\n"
                   "int hblkhd;   /* space in mmapped regions */\n"
                   "int usmblks;  /* maximum total allocated space */\n"
                   "int fsmblks;  /* space available in freed fastbin blocks */\n"
                   "int uordblks; /* total allocated space */\n"
                   "int fordblks; /* total free space */\n"
                   "int keepcost; /* top-most, releasable (via malloc_trim) space */\n"
                   "};\n");

    printf("======================before test=================================\n");
    print_info();
    //test_aligned_alloc();
    //test_memalign();
    //test_mallopt_M_PERTURB();
    //test_mallopt_M_MMAP_THRESHOLD();
    //test_mallopt_M_TRIM_THRESHOLD();
    //test_mtrace();
    //test_brk_sbrk();
    //test_mmap();
    printf("=======================after test===================================\n");
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


    return 0;
}