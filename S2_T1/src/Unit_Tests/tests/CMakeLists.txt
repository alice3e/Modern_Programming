cmake_minimum_required(VERSION 3.2...3.26)
set(CMAKE_CXX_STANDARD 23)
project(Unit_tests_code)

include_directories(lib)

add_executable(RUN_hw1_tests hw1_tests.cpp)

target_link_libraries(RUN_hw1_tests HW1_insertion_sort)

target_link_libraries(RUN_hw1_tests gtest gtest_main)

add_test(test_hw1 hw1_tests)