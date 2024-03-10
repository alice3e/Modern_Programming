cmake_minimum_required(VERSION 3.26)
project(hw1_test_dir)
set(CMAKE_CXX_STANDARD 23)

add_executable(hw1_test_run hw1_tests.cpp)

# We should find a full path to our lib using find_path
# than we include out static lib from other dir

find_path (LIB_INCLUDES_2 intr_sort.h ../../hw1_insertion_sort/src)
include_directories(${LIB_INCLUDES_2})
message(${LIB_INCLUDES_2})

# linking Google_Tests_run with SortingAlgos_lib which will be tested
target_link_libraries(hw1_test_run hw1_lib)
target_link_libraries(hw1_test_run gtest gtest_main)