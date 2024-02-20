target_sources(HW1_insertion_sort
        PRIVATE
        intr_sort.cpp
        intr_sort.h
)

target_include_directories(HW1_insertion_sort PRIVATE
        "${PROJECT_SOURCE_DIR}/src"
)