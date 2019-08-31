#include <iostream>
#include <cstring>
#include <signal.h>
#include "common.h"
#include <iostream>
#include <vector>
#include <map>
#include <functional>

int endTest()
{
    std::cout << "end" << std::endl;
    return 10;
}

std::map<int, std::function<int(void)>> testList =
{
{ 1, print_info },
{ 2, endTest } };
std::map<int, std::string> testListName =
{
{ 1, "print_info" },
{ 2, "end" } };

int main()
{
//    printf("struct mallinfo\n"
//                   "{\n"
//                   "int arena;    /* non-mmapped space allocated from system */\n"
//                   "int ordblks;  /* number of free chunks */\n"
//                   "int smblks;   /* number of fastbin blocks */\n"
//                   "int hblks;    /* number of mmapped regions */\n"
//                   "int hblkhd;   /* space in mmapped regions */\n"
//                   "int usmblks;  /* maximum total allocated space */\n"
//                   "int fsmblks;  /* space available in freed fastbin blocks */\n"
//                   "int uordblks; /* total allocated space */\n"
//                   "int fordblks; /* total free space */\n"
//                   "int keepcost; /* top-most, releasable (via malloc_trim) space */\n"
//                   "};\n");

    printf("======================测试列表=================================\n");

    for (auto iter : testListName)
    {
        std::cout << iter.first << " :" << iter.second << std::endl;
    }

    //test_aligned_alloc();
    //test_memalign();
    //test_mallopt_M_PERTURB();
    //test_mallopt_M_MMAP_THRESHOLD();
    //test_mallopt_M_TRIM_THRESHOLD();
    //test_mtrace();
    //test_brk_sbrk();
    //test_mmap();
    //test_getrusage();
    //test_getrlimit();
    //testSetJmp();
    //test_ucontext();
    //testSignal();

    //print_info();

    char t[111];
    while (1)
    {
        fgets(t, 4, stdin);
        int no = atoi(t);
        auto func = testList.find(no);
        if (func == testList.end())
        {
            std::cout << "error no:" << no << std::endl;
            break;
        }
        if (func->second() == 10)
            break;
    }
    printf("=======================测试结束===================================\n");

    return 0;
}
