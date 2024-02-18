cmake_minimum_required(VERSION 3.26)
project(HW1_insertion_sort)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        ${PROJECT_NAME} main.cpp
        intr_sort.cpp
        intr_sort.h
        )