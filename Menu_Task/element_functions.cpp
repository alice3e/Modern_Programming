
// Created by alicee on 06.12.2023.
//
#include "element_functions.h"
#include <iostream>
//const IBusko::MenuItem* IBusko::show_menu(const MenuItem* current)

const alicee::MenuItem* ::element_show_menu(const alicee::MenuItem* current){
    std::cout << current->title << ": " << std::endl;
    std::cout << "0 - вернутся на уровень выше / выйти из программы" << std::endl;
    for(int i = 0; i < current->children_count;i++){
        std::cout << i+1 << " - " << current->children[i]->title << std::endl;
    }
    std::cout << "Выберите пункт меню: ";

    //TODO : User's wrong input capture
    int n;
    std::cin >> n;
    if(n==0){
        if(current->parent == nullptr){
            std::cout << "Завершение программы!" << std::endl;
            std::exit(0); // return 0 - возвращает signal 11: SIGSEGV
        }else{
            std::cout << "Возврат на уровень выше" << std::endl << std::endl;
            return current->parent;
        }
    }
    //std::cout << std::endl << current->children[n-1]->title << std::endl;
    std::cout << std::endl;
    return current->children[n-1];
};

