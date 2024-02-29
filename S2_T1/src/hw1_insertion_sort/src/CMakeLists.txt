
cmake_minimum_required(VERSION 3.26)

project(intr_sort)

set(SOURCE_FILES
        intr_sort.cpp
)

set(HEADER_FILES
        intr_sort.h
)

add_library(hw1_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})