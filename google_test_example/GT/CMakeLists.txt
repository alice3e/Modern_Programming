cmake_minimum_required(VERSION 3.26)
project(test_dir)

set(CMAKE_CXX_STANDARD 23)

add_executable(test_dir_run test1.cpp)

add_subdirectory(lib)

# linking Google_Tests_run with SortingAlgos_lib which will be tested
target_link_libraries(test_dir_run some_lib)

target_link_libraries(test_dir_run gtest gtest_main)