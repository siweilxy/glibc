#include <iostream>
#include <malloc.h>
#include "common.h"

size_t  heap_malloc_total, heap_free_total,mmap_total, mmap_count;

void print_info()
{
    struct mallinfo mi = mallinfo();
    printf("count by itself:\n");
    printf("\theap_malloc_total=%lu heap_free_total=%lu heap_in_use=%lu\n\tmmap_total=%lu mmap_count=%lu\n",
           heap_malloc_total*1024, heap_free_total*1024, heap_malloc_total*1024-heap_free_total*1024,
           mmap_total*1024, mmap_count);
    printf("count by mallinfo:\n");
    printf("\theap_malloc_total=%lu heap_free_total=%lu heap_in_use=%lu\n\tmmap_total=%lu mmap_count=%lu\n",
           mi.arena, mi.fordblks, mi.uordblks,
           mi.hblkhd, mi.hblks);
    printf("from malloc_stats:\n");
    malloc_stats();
}

int main() {
    std::cout << "test start" << std::endl;
    print_info();
    //test_aligned_alloc();
    //test_memalign();
    //test_mallopt_M_PERTURB();
    //test_mallopt_M_MMAP_THRESHOLD();
    test_mallopt_M_TRIM_THRESHOLD();
    print_info();

    return 0;
}