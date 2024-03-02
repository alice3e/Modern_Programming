project(Long_numbers_src)
cmake_minimum_required(VERSION 3.26)


set(SOURCE_FILES
        long_number.cpp
)

set(HEADER_FILES
        long_number.hpp
)

add_library(SCL_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

