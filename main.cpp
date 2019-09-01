#include <iostream>
#include <cstring>
#include <signal.h>
#include "common.h"
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <unistd.h>

int endTest()
{
    std::cout << "end" << std::endl;
    return 10;
}

std::map<int, std::function<int(void)>> testList =
{
{ 1, print_info },
{ 2, endTest },
{ 3, test_realloc },
{ 4, test_aligned_alloc },
{ 5, test_mallopt_M_MAP_MAX },
{ 6, test_mallopt_M_MMAP_THRESHOLD },
{ 7, test_mcheck },
{ 8, test_mprobe },
{ 9, test_mtrace },
{ 10, test_brk_sbrk },
{ 11, test_pipe } };

std::map<int, std::string> testListName =
{
{ 1, "print_info" },
{ 2, "end" },
{ 3, "test_realloc" },
{ 4, "test_aligned_alloc" },
{ 5, "test_mallopt_M_MAP_MAX" },
{ 6, "test_mallopt_M_MMAP_THRESHOLD" },
{ 7, "test_mcheck" },
{ 8, "test_mprobe" },
{ 9, "test_mtrace" },
{ 10, "test_brk_sbrk" },
{ 11, "test_pipe" } };

int main()
{
    printf("======================测试列表=================================\n");

    for (auto iter : testListName)
    {
        std::cout << iter.first << " :" << iter.second << "pid is " << getpid()
                << std::endl;
    }

    char t[111];
    while (1)
    {
        std::cout << "输入测试id" << std::endl;
        fgets(t, 4, stdin);
        int no = atoi(t);
        auto func = testList.find(no);
        if (func == testList.end())
        {
            std::cout << "error no:" << no << " pid is " << getpid()
                    << " 输入的id是：" << t << std::endl;
            continue;
        }

        int ret = func->second();
        if (ret == 10)
        {
            printf("=======================测试结束===================================\n");
            break;
        } else if (ret != 0)
        {
            std::cout << "test is error" << " pid is " << getpid() << std::endl;
            break;
        }
    }
    return 0;
}
