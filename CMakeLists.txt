cmake_minimum_required(VERSION 3.5)
project(glibc)


set(CMAKE_CXX_STANDARD 11)
enable_language(ASM)
include_directories(common)

link_directories(/home/siwei/github/glibc/build)

add_definitions("-g")
add_executable(glibc main.cpp mem/memtest.cpp common/common.cpp aio/aiotest.cpp resourceUsageAndLimitation/testResourceUsageAndLimitation.cpp CPU/testCpu.cpp jump/testJump.cpp ucontext/ucontext.cpp signal/testSignal.cpp)
target_link_libraries(glibc mcheck)
