cmake_minimum_required(VERSION 3.2...3.26)
project(S2_T1)

set(CMAKE_CXX_STANDARD 23)

enable_testing()

add_subdirectory(Unit_Tests)
add_subdirectory(hw1_insertion_sort)
add_subdirectory(HW4_base_theory)
add_subdirectory(menu_task)

include_directories(Unit_Tests)
include_directories(hw1_insertion_sort)
include_directories(HW4_base_theory)
include_directories(menu_task)
