// Created by alicee on 05.10.2023.
// EX main.cpp
// Земля пухом брат, будем помнить вечно...🕯️🕯️🕯️
#include <iostream>
#include <random>
#include <algorithm>
#define INF 10e9

// FUNC DECLARATION
void merge_rec(std::vector<int> &v, int left, int right);
void rnd_arr(int a[], const int sz, int max_el_size);
void out(int v[],const int sz);


void rnd_arr(int a[], const int sz, int max_el_size) { // max_el_size = 1eX - максимальная длина элемента
    std::mt19937 rnd(time(NULL));
    for (int i = 0; i < sz; i++) {
        a[i] = (rnd() % max_el_size);
    }
}

void arr_copy(int original[],int copy[],const int sz){
    for(int i = 0; i < sz;i++){
        copy[i] = original[i];
    }
}

void out(int v[],const int sz) {
    for (int i = 0; i < sz;i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;
}

// MAIN PART
void merger(int v[], int left, int middle, int right) {
    // arr1 & arr2 - creation (split V in half)
    int arr1_size, arr2_size;
    arr1_size = middle - left + 1;
    arr2_size = right - middle;
    int arr1[arr1_size + 1];
    int arr2[arr2_size + 1];;
    arr1[arr1_size] = INF;
    arr2[arr2_size] = INF;
    // arr1 & arr2 forming
    for (int i = 0; i < arr1_size; i++) {
        arr1[i] = v[left + i];
    }
    for (int i = 0; i < arr2_size; i++) {
        arr2[i] = v[middle + i + 1];
    }

    //MERGING BACK
    int k = left, i = 0, j = 0; // k - main, i - arr1,j - arr2
    // k = left - ОБЯЗАТЕЛЬНО, ТК МЫ МАССИВ ДЕЛИМ ПРИ РЕКУРСИИ И РАБОТАЕМ ТОЛЬКО С ПОЛОВИНОЙ
    while (i < arr1_size && j < arr2_size) {
        if (arr1[i] < arr2[j]) {
            v[k] = arr1[i];
            i++;
        } else {
            v[k] = arr2[j];
            j++;
        }
        k++; // next main_v elem
    }
    while (i < arr1_size) {
        v[k] = arr1[i];
        i++;
        k++;
    }
    while (j < arr2_size) {
        v[k] = arr2[j];
        j++;
        k++;
    }

}

void merge_rec(int a[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        merge_rec(a, left, middle);
        merge_rec(a, middle + 1, right);
        merger(a, left, middle, right);
    }
}


int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    // MAIN MAIN

    const int size_a = 10e2; // sizeof(a) / sizeof(a[0])
    int a[size_a];
    rnd_arr(a, size_a, 10e3);
    merge_rec(a,0,size_a-1);
    out(a,size_a);
    return 0;
}