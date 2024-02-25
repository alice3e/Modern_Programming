cmake_minimum_required(VERSION 3.26)

project(some_proj)

set(SOURCE_FILES
        code_example.cpp
)

set(HEADER_FILES
        code_example.hpp
)

add_library(some_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
