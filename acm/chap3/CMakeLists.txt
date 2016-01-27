cmake_minimum_required(VERSION 3.3)
project(chap3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    a.c
    b.c
    c.c)

add_executable(chap3 ${SOURCE_FILES})