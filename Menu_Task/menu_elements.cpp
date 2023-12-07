//
// Created by alicee on 06.12.2023.
//
#include "menu_elements.h"
#include "element_functions.h"
// title; (*itemfunction); *parent; *children; children_count;



const alicee::MenuItem alicee::ALGEBRA_LEVEL1{
        "Меню изучения Алгебры", element_show_menu, &MAIN_LEVEL0, nullptr, 0
};

const alicee::MenuItem alicee::MATHAN_LEVEL1{
        "Меню изучения МатАнализа", element_show_menu, &MAIN_LEVEL0, nullptr, 0
};

namespace main_children{
    const alicee::MenuItem* const children[] = {
            &alicee::ALGEBRA_LEVEL1,
            &alicee::MATHAN_LEVEL1
    };
}

const alicee::MenuItem alicee::MAIN_LEVEL0{
        "Главное Меню", element_show_menu, nullptr, main_children::children, 2
};