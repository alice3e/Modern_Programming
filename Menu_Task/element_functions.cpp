#include "element_functions.h"
#include <iostream>


const alicee::MenuItem *MenuFunctions::global_show_menu(const alicee::MenuItem *current) {
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

const alicee::MenuItem *MenuFunctions::element_show_menu(const alicee::MenuItem *current) {
    std::cout << current->title << ": " << std::endl;

    return global_show_menu(current);
};

const alicee::MenuItem *MenuFunctions::algebra_show_menu(const alicee::MenuItem *current) {
    std::cout << current->title << ": " << std::endl;

    std::cout << "Скопируйте и откройте данную ссылку в браузере!" << std::endl;
    if (current->title == "Хочу научиться складывать!") {
        std::cout << "https://resh.edu.ru/subject/lesson/6865/conspect/236927/" << std::endl;
    } else if (current->title == "Хочу научиться вычитать!") {
        std::cout << "https://skysmart.ru/articles/mathematic/vychitanie-stolbikom" << std::endl;
    } else if (current->title == "Хочу научиться делить!") {
        std::cout << "http://spacemath.xyz/delenie/" << std::endl;
    } else if (current->title == "Хочу научиться умножать!") {
        std::cout << "https://skysmart.ru/articles/mathematic/umnozhenie-v-stolbik" << std::endl;
    } else {
        std::cout << "произошла ошибка, просьба написать tg @alice3e" << std::endl;
    }

    return global_show_menu(current);
};

const alicee::MenuItem *MenuFunctions::mathan_show_menu(const alicee::MenuItem *current) {
    std::cout << current->title << ": " << std::endl;

    std::cout << "Скопируйте и откройте данную ссылку в браузере!" << std::endl;
    if (current->title == "Хочу изучить дифференциальное исчисление!") {
        std::cout
                << "https://hti.urfu.ru/fileadmin/user_upload/site_15078/dokumenty/zaochniki/2_matem_analiz_funkcii_odnoi_peremennoi.pdf"
                << std::endl;
    } else if (current->title == "Хочу изучить интегральное исчисление!") {
        std::cout << "https://www.booksite.ru/fulltext/1/001/008/055/368.htm" << std::endl;
    } else {
        std::cout << "произошла ошибка, просьба написать tg @alice3e" << std::endl;
    }

    return global_show_menu(current);
};