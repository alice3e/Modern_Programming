cmake_minimum_required(VERSION 3.26)

project(SCL)

set(CMAKE_CXX_STANDARD 23)

add_executable(main main.cpp)

include_directories(src)
add_subdirectory(src)

target_link_libraries(main SCL_lib)
