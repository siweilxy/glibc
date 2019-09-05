/*
 * testSockets.cpp
 *
 *  Created on: Sep 4, 2019
 *      Author: siwei
 */

#include <iostream>
#include <net/if.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
int testSocketsInterface()
{
    int ret = 0;
    ret = if_nametoindex("enp5s0");
    std::cout << "if_nametoindex 返回的是 enp5s0的id号，如果沒有這個網卡，則返回0，这里enp5s0的id为"
            << ret << std::endl;

    std::cout<<"if_nameindex()是获得所有的网卡信息，如下："<<std::endl;
    struct if_nameindex *head, *ifni;
    ifni = if_nameindex();
    head = ifni;

    if (head == NULL)
    {
        perror("if_nameindex()");
        return -1;
    }

    while (ifni->if_index != 0)
    {
        printf("Interfece %d : %s\n", ifni->if_index, ifni->if_name);
        ifni++;
    }

    if_freenameindex(head);
    head = NULL;
    ifni = NULL;


    std::cout<<"if_indextoname是使用id来获取网卡的名字，如下id为1的网卡为："<<std::endl;
    int saved_errno = errno;
    char if_name[IFNAMSIZ] = {'\0'};
    unsigned int if_index = (unsigned int )atoi("1");

    char *name = if_indextoname(if_index, if_name);
    if (name == NULL && errno == ENXIO) {
        fprintf(stderr, "Index %d : No such device\n", if_index);
        exit(EXIT_FAILURE);
    }

    errno = saved_errno;

    printf("Index %d : %s\n", if_index, if_name);

    return 0;
}

