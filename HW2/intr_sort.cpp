//intr_sort.cpp
#include "intr_sort.h"

void BubbleSort::srt(int arr[],const int &n){ // TODO : make it work!
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int x = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = x;
            }
        }
    }
}