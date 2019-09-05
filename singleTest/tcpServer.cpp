/*
 * tcpServer.cpp
 *
 *  Created on: Sep 4, 2019
 *      Author: siwei
 */

#include <iostream>
#include <net/if.h>
int main()
{
    int ret =0;
    ret = if_nametoindex("eth0");
    std::cout<<"ret is "<<ret<<std::endl;
    return 0;
}
