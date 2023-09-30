//
// Created by alicee on 28.09.2023.
//
#include "io_arr.h"


void IOArray::print_array(int *arr, const int &n) {
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}