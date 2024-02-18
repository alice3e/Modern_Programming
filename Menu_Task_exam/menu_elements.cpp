#include "menu_elements.h"
#include "element_functions.h"


namespace main_children {
    const alicee::MenuItem *const children[] = {
            &EDUCATION_LEVEL1,
            &PROGRAM_EXIT
    };
}

namespace education_children {
    const alicee::MenuItem *const children[] = {
            &FIRSTGRADE_LEVEL2,
            &SECONDGRADE_LEVEL2,
            &THIRDGRADE_LEVEL2,
            &GO_BACK_EDUCATION
    };
}

namespace firstgrade_children {
    const alicee::MenuItem *const children[] = {
            &FIRSTGRADE_RUSSIAN_LEVEL3,
            &FIRSTGRADE_LITERATURE_LEVEL3,
            &FIRSTGRADE_MATH_LEVEL3,
            &FIRSTGRADE_SPORTS_LEVEL3,
            &GO_BACK_FIRSTGRADE
    };
}
namespace secondgrade_children {
    const alicee::MenuItem *const children[] = {
            //&EDUCATION_LEVEL1
    };
}
namespace thirdgrade_children {
    const alicee::MenuItem *const children[] = {
            //&EDUCATION_LEVEL1
    };
}


// title, указатель на функц, *parent, arr[ &child1 , &child2 etc], children_count
const alicee::MenuItem PROGRAM_EXIT{
        "Выход из программы!", menu_functions::program_exit, nullptr, nullptr, 0
};

const alicee::MenuItem GO_BACK_EDUCATION{
        "Главное меню", menu_functions::go_back, &EDUCATION_LEVEL1, nullptr, 0
};
const alicee::MenuItem GO_BACK_FIRSTGRADE{
        "Главное меню", menu_functions::go_back, &FIRSTGRADE_LEVEL2, nullptr, 0
};


const alicee::MenuItem MAIN_LEVEL0{
    "Главное меню", menu_functions::show_menu, nullptr, main_children::children, 2
};


const alicee::MenuItem EDUCATION_LEVEL1{
        "Меню выбора класса обучения", menu_functions::show_menu, &MAIN_LEVEL0, education_children::children, 4
};


const alicee::MenuItem FIRSTGRADE_LEVEL2{
        "Меню выбора предметов 1ого класса", menu_functions::show_menu, &EDUCATION_LEVEL1, firstgrade_children::children, 5
};
const alicee::MenuItem SECONDGRADE_LEVEL2{
        "Меню выбора предметов 2ого класса", menu_functions::show_menu, &EDUCATION_LEVEL1, secondgrade_children::children, 0
};
const alicee::MenuItem THIRDGRADE_LEVEL2{
        "Меню выбора предметов 3ого класса", menu_functions::show_menu, &EDUCATION_LEVEL1, thirdgrade_children::children, 0
};


const alicee::MenuItem FIRSTGRADE_RUSSIAN_LEVEL3{
        "Первый класс - Русский язык", menu_functions::show_menu, &FIRSTGRADE_LEVEL2, nullptr, 0
};
const alicee::MenuItem FIRSTGRADE_LITERATURE_LEVEL3{
        "Первый класс - Литература", menu_functions::show_menu, &FIRSTGRADE_LEVEL2, nullptr, 0
};
const alicee::MenuItem FIRSTGRADE_MATH_LEVEL3{
        "Первый класс - Математика", menu_functions::show_menu, &FIRSTGRADE_LEVEL2, nullptr, 0
};
const alicee::MenuItem FIRSTGRADE_SPORTS_LEVEL3{
        "Первый класс - Физическая Культура", menu_functions::show_menu, &FIRSTGRADE_LEVEL2, nullptr, 0
};
