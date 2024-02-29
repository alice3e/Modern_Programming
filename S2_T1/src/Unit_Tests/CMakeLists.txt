cmake_minimum_required(VERSION 3.26)
project(google_test_example)

set(CMAKE_CXX_STANDARD 17)



include_directories(src) # for main.cpp for #include "some_lib.h"

add_subdirectory(src) # for CMakeLists.txt inside directories to run
add_subdirectory(GT) # for CMakeLists.txt inside directories to run

target_link_libraries(google_test_example some_lib)
