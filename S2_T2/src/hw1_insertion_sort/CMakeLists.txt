cmake_minimum_required(VERSION 3.26)

project(HW1_insertion_sort)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(src)
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} hw1_lib)