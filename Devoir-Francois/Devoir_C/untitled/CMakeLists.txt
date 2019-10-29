cmake_minimum_required(VERSION 3.15)
project(untitled C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(untitled main.c)
