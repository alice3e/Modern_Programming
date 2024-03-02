#include "element_functions.h"

#include <iostream>


const alicee::MenuItem *MenuFunctions::show_global_menu(const alicee::MenuItem *current) {
    std::cout << "0 - вернутся на уровень выше / выйти из программы" << std::endl;
    for (int i = 0; i < current->children_count; i++) {
        std::cout << i + 1 << " - " << current->children[i]->title << std::endl;
    }

    std::cout << "Выберите пункт меню: ";
    int n;
    do {
        std::cin >> n;
        if (n > current->children_count) std::cout << "Введен неверный номер меню, попробуйте снова!" << std::endl;
    } while (n > current->children_count);

    if (n == 0) {
        if (current->parent == nullptr) {
            std::cout << "Завершение программы!" << std::endl;
            std::exit(0); // return 0 - возвращает signal 11: SIGSEGV
        } else {
            std::cout << "Возврат на уровень выше" << std::endl << std::endl;
            return current->parent;
        }
    }
    std::cout << std::endl;

    return current->children[n - 1];
}

const alicee::MenuItem *MenuFunctions::show_element_menu(const alicee::MenuItem *current) {
    std::cout << current->title << ": " << std::endl;

    return show_global_menu(current);
};

const alicee::MenuItem *MenuFunctions::show_element_with_link_menu(const alicee::MenuItem *current) {
    std::cout << current->title << ": " << std::endl;
    std::cout << "Вся Информация по ссылке!" << std::endl << current->information_link << std::endl;
    return show_global_menu(current);
};