cmake_minimum_required(VERSION 3.5)
project(glibc)


set(CMAKE_CXX_STANDARD 11)
enable_language(ASM)
include_directories(common)

link_directories(/home/siwei/github/glibc/build)


add_executable(glibc main.cpp mem/memtest.cpp)
target_link_libraries(glibc test)
