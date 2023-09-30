cmake_minimum_required(VERSION 3.26)
project(HW1)

set(CMAKE_CXX_STANDARD 23)

add_executable(HW1 main.cpp
        intr_sort.h
        intr_sort.cpp
        io_arr.cpp
        io_arr.h)
