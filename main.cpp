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
{ 2, endTest },
{ 3, test_realloc },
{ 4, test_aligned_alloc },
{ 5, test_mallopt_M_MAP_MAX },
{ 6, test_mallopt_M_MMAP_THRESHOLD },
{ 7, test_mcheck } };
std::map<int, std::string> testListName =
{
{ 1, "print_info" },
{ 2, "end" },
{ 3, "test_realloc" },
{ 4, "test_aligned_alloc" },
{ 5, "test_mallopt_M_MAP_MAX" },
{ 6, "test_mallopt_M_MMAP_THRESHOLD" },
{ 7, "test_mcheck" } };

int main()
{

    printf("======================测试列表=================================\n");

    for (auto iter : testListName)
    {
        std::cout << iter.first << " :" << iter.second << std::endl;
    }

    char t[111];
    while (1)
    {
        fgets(t, 4, stdin);
        int no = atoi(t);
        auto func = testList.find(no);
        if (func == testList.end())
        {
            std::cout << "error no:" << no << std::endl;
            continue;
        }

        int ret = func->second();
        if (ret == 10)
            break;
        else if(ret != 0)
        {
            std::cout<<"test is error"<<std::endl;
        }
    }
    printf("=======================测试结束===================================\n");

    return 0;
}
