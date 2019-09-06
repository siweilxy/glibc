cmake_minimum_required(VERSION 3.5)
project(glibc)


set(CMAKE_CXX_STANDARD 11)
enable_language(ASM)
include_directories(common)

link_directories(/home/siwei/github/glibc/build)

message ("WARNING $ENV{HOME}")

add_definitions("-g")
add_executable(glibc main.cpp masterAndSlave/slave.cpp masterAndSlave/master.cpp masterAndSlave/masterAndSlave.cpp debugSupport/testDebuggingSupport.cpp sockets/testSockets.cpp pipe/pipeTest.cpp mem/memtest.cpp common/common.cpp aio/aiotest.cpp resourceUsageAndLimitation/testResourceUsageAndLimitation.cpp CPU/testCpu.cpp jump/testJump.cpp ucontext/ucontext.cpp signal/testSignal.cpp)
target_link_libraries(glibc mcheck)

add_subdirectory($ENV{HOME}/github/glibc/singleTest/ )
SET(EXECUTABLE_OUTPUT_PATH $ENV{HOME}/github/glibc/bin)

