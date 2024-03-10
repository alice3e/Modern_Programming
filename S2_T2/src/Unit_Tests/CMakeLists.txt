cmake_minimum_required(VERSION 3.26)
project(global_test)
set(CMAKE_CXX_STANDARD 23)


add_subdirectory(lib)
add_subdirectory(hw1_tests_dir)
add_subdirectory(SCL_tests_dir)

include_directories(lib)
include_directories(hw1_tests_dir)
include_directories(SCL_tests_dir)



