cmake_minimum_required(VERSION 3.26)
project(google_test_example)

set(CMAKE_CXX_STANDARD 17)

add_executable(google_test_example_run main.cpp)

include_directories(src) # for main.cpp for #include "some_lib.h"

add_subdirectory(src) # for CMakeLists.txt inside directories to run
add_subdirectory(GT) # for CMakeLists.txt inside directories to run

target_link_libraries(google_test_example_run some_lib)

# ПРОЧИТАЙТЕ
#В вашем примере кода вы создаете проект google_test_example с использованием Google Test. Вы устанавливаете стандарт C++ на 17, включаете директорию src, добавляете подпроект из src и связываете ваш исполняемый файл google_test_example с библиотекой some_lib.
#Однако, порядок инструкций в CMakeLists.txt важен. В вашем случае, перед тем как связать исполняемый файл с библиотекой some_lib, вы должны сначала создать исполняемый файл.







