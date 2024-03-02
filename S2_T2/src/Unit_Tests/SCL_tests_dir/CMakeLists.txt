cmake_minimum_required(VERSION 3.26)
project(SCL_test_dir)
set(CMAKE_CXX_STANDARD 23)

add_executable(SCL_test_run SCL_tests.cpp)

# We should find a full path to our lib using find_path
# than we include out static lib from other dir


message('')
message(${LIB_INCLUDES})
message('')

# linking Google_Tests_run with SortingAlgos_lib which will be tested
target_link_libraries(SCL_test_run SCL_lib)
target_link_libraries(SCL_test_run gtest gtest_main)