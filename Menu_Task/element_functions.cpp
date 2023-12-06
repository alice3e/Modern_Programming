
// Created by alicee on 06.12.2023.
//
#include "element_functions.h"
#include <iostream>
//const IBusko::MenuItem* IBusko::show_menu(const MenuItem* current)

const alicee::MenuItem* ::element_show_menu(const alicee::MenuItem* current){
    std::cout << "0 - вернутся на уровень выше / выйти из программы" << std::endl;
    for(int i = 0; i < current->children_count;i++){
        std::cout << i+1 << " - " << current->children[i]->title << std::endl;
    }
    std::cout << "Выберите пункт меню: ";
    int n;
    std::cin >> n;
    std::cout << std::endl << current->children[n]->title << std::endl;
    return current->children[n];
};

