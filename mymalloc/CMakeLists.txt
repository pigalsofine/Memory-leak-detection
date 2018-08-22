cmake_minimum_required(VERSION 3.9)
project(mymalloc C)

set(CMAKE_C_STANDARD 99)

add_executable(mymalloc main.c mymalloc.c mymalloc.h)