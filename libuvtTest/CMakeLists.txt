cmake_minimum_required(VERSION 3.5)
project(mkfifo)


set(CMAKE_CXX_STANDARD 11)
include_directories(common)

add_definitions("-g")

add_executable(uvTest uvTest.cpp )

target_link_libraries(uvTest uv)


SET(EXECUTABLE_OUTPUT_PATH  $ENV{HOME}/github/glibc/bin)



