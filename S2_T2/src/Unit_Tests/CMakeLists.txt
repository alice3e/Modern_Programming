cmake_minimum_required(VERSION 3.26)
project(global_test)
set(CMAKE_CXX_STANDARD 23)


add_subdirectory(lib)
add_subdirectory(hw1_tests_dir)
add_subdirectory(SCL_tests_dir)

include_directories(lib)
include_directories(hw1_tests_dir)
include_directories(SCL_tests_dir)

find_path (LIB_INCLUDES long_number.hpp ../../SCL/Long_Numbers/src)
include_directories(${LIB_INCLUDES})

find_path (LIB_INCLUDES intr_sort.h ../../hw1_insertion_sort/src)
include_directories(${LIB_INCLUDES})