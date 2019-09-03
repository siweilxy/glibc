cmake_minimum_required(VERSION 3.5)
project(mkfifo)


set(CMAKE_CXX_STANDARD 11)
include_directories(common)

add_definitions("-g")
add_executable(send send.cpp )
add_executable(recv recv.cpp )
target_link_libraries(send mcheck)
target_link_libraries(recv mcheck)

SET(EXECUTABLE_OUTPUT_PATH /home/siwei/github/glibc/bin)


#install(FILES send DESTINATION /home/siwei/github/glibc/bin)
#install(FILES recv DESTINATION /home/siwei/github/glibc/bin)

