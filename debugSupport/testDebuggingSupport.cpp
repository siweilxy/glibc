/*
 * testDebuggingSupport.cpp
 *
 *  Created on: Sep 6, 2019
 *      Author: siwei
 */

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

void print_trace(void)
{
    void *array[10];
    size_t size;
    char **strings;
    size_t i;

    size = backtrace(array, 10);
    strings = backtrace_symbols(array, size);
    if (NULL == strings)
    {
        perror("backtrace_synbols");
        exit(EXIT_FAILURE);
    }

    printf("Obtained %zd stack frames.\n", size);

    for (i = 0; i < size; i++)
        printf("%s\n", strings[i]);

    free(strings);
    strings = NULL;
}

/* A dummy function to make the backtrace more interesting. */
void dummy_function(void)
{
    print_trace();
}

int test_backtrace()
{
    dummy_function();
    return 0;
}
