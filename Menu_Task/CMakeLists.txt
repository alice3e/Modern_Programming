cmake_minimum_required(VERSION 3.26)
project(Menu_Task)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Menu_Task
        main.cpp
        menu.h
        menu_elements.h
        element_functions.h
        menu_elements.cpp
        element_functions.cpp
)
