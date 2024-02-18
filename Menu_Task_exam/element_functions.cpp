#include "element_functions.h"

#include <iostream>

namespace menu_functions{

    const alicee::MenuItem *show_menu(const alicee::MenuItem *current){
        std::cout << "|| " << current->title << " ||" << std::endl;
        for (int i = 0; i < current->children_count; i++) {
            std::cout << i+1 << " - " << current->children[i]->title << std::endl;
        }


        std::cout << "Выберите элемент меню по его НОМЕРУ: ";
        int n;
        do{
            std::cin >> n;
            if (n > current->children_count) std::cout << "Введен неверный номер, попробуйте снова!: " << std::endl;
        }while(n > current->children_count);


        std::cout << std::endl;
        return current->children[n - 1];
    }


    const alicee::MenuItem *program_exit(const alicee::MenuItem *current){
        std::cout << "ВЫХОД ИЗ ПРОГРАММЫ!" << std::endl;
        std::exit(0);
    }

    const alicee::MenuItem *go_back(const alicee::MenuItem *current){
        return current->parent->parent;
    }

}

/*
 * const alicee::MenuItem *show_menu(const alicee::MenuItem *current){
        std::cout << "|| " << current->title << " ||" << std::endl;
        std::cout << "0 - вернутся на уровень выше / выйти из программы" << std::endl;
        for (int i = 0; i < current->children_count; i++) {
            std::cout << i + 1 << " - " << current->children[i]->title << std::endl;
        }


        std::cout << "Выберите элемент меню по его номеру: ";
        int n;
        do{
            std::cin >> n;
            if (n > current->children_count) std::cout << "Введен неверный номер, попробуйте снова!: " << std::endl;
        }while(n > current->children_count);


        if(n==0) {
            if(current->parent == nullptr){
                std::cout << "Выход из программы!" << std::endl;
                std::exit(0);
            }else{
                std::cout << "Возврат на уровень выше!:" << std::endl;
                return current->parent;
            }
        }else{
            std::cout << std::endl;
            return current->children[n - 1];
        }

        std::cout << "ОШИБКА В КОДЕ!" << std::endl;
        std::exit(0);
    }
 */