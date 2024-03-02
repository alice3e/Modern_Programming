cmake_minimum_required(VERSION 3.26)
project(Menu_Task)

set(CMAKE_CXX_STANDARD 23)

set(HEADERS
        src/menu.h
        src/menu_elements.h
        src/element_functions.h
)

set(SOURCES
        src/menu_elements.cpp
        src/element_functions.cpp
        main.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})