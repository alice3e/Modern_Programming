//main.cpp
#include "intr_sort.h"
#include "io_arr.h"

int main() {
    setlocale(LC_ALL, "Russian");

    // ARRAY INPUT
    int arr[] = {1,2,3,5,8,7,6};
    const int arr_size = std::size(arr);

    // SORTING
    BubbleSort::srt(arr,arr_size);

    //OUTPUT
    // Privet Sasha!!
    IOArray::print_array(arr,arr_size);
}
