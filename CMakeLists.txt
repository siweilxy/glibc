cmake_minimum_required(VERSION 3.5)
project(glibc)

set(CMAKE_CXX_STANDARD 11)

include_directories(common)

add_executable(glibc main.cpp mem/memtest.cpp)
