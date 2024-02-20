//
// Created by alicee on 18.02.2024.
//
//main.cpp
#include <iomanip>
#include <iostream>
#include "src/intr_sort.h"


std::vector<int> inp(int vec_size);
void out(std::vector<int> v);

std::vector<int> inp(int vec_size) {
    std::vector<int> v(vec_size);
    for (int i = 0; i < vec_size; i++) {
        std::cin >> v[i];
    }
    return v;
}

void out(std::vector<int> v) {
    for (int i = 0 ; i < v.size() ; i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {


    setlocale(LC_ALL, "Russian");
    std::cout << "enter size of std::vector: ";
    int n;
    std::cin >> n;
    std::cout << "enter elements of std::vector: ";

    std::vector<int> vec = inp(n);
    std::vector<int> answ;


    IntrSort::srt(answ,vec);

    std::cout << std::setw(20) << "sorted elements: ";

    out(answ);
    std::cout << std::setw(20) << "indexes: ";
    for(int i = 0;i<answ.size();i++){
        std::cout << i+1 << ' ';
    }

    std::cout << std::endl;

    return 0;
}

