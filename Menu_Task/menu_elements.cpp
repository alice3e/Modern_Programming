#include "menu_elements.h"
#include "element_functions.h"

// STRUCT:
// level0 -> level1 -> .... -> levelN

namespace main_children {
    const alicee::MenuItem *const children[] = {
            &alicee::SUBJECT_CHOICE_LEVEL1
    };
}

namespace main_education_children {
    const alicee::MenuItem *const children[] = {
            &alicee::ALGEBRA_LEVEL2,
            &alicee::MATHAN_LEVEL2
    };
}

namespace mathan_children {
    const alicee::MenuItem *const children[] = {
            &alicee::MATHAN_LEVEL3_1,
            &alicee::MATHAN_LEVEL3_2
    };
}

namespace algebra_children {
    const alicee::MenuItem *const children[] = {
            &alicee::ALGEBRA_LEVEL3_1,
            &alicee::ALGEBRA_LEVEL3_2,
            &alicee::ALGEBRA_LEVEL3_3,
            &alicee::ALGEBRA_LEVEL3_4
    };
}

const alicee::MenuItem alicee::MAIN_LEVEL0{
        "Главное Меню", MenuFunctions::element_show_menu, nullptr, main_children::children, 1
};

const alicee::MenuItem alicee::SUBJECT_CHOICE_LEVEL1{
        "Меню программ обучения", MenuFunctions::element_show_menu, &MAIN_LEVEL0, main_education_children::children, 2
};

const alicee::MenuItem alicee::ALGEBRA_LEVEL2{
        "Меню изучения Алгебры", MenuFunctions::element_show_menu, &SUBJECT_CHOICE_LEVEL1, algebra_children::children, 4
};

const alicee::MenuItem alicee::MATHAN_LEVEL2{
        "Меню изучения МатАнализа", MenuFunctions::element_show_menu, &SUBJECT_CHOICE_LEVEL1, mathan_children::children, 2
};


const alicee::MenuItem alicee::ALGEBRA_LEVEL3_1{
        "Хочу научиться складывать!", MenuFunctions::algebra_show_menu, &ALGEBRA_LEVEL2, nullptr, 0
};
const alicee::MenuItem alicee::ALGEBRA_LEVEL3_2{
        "Хочу научиться вычитать!", MenuFunctions::algebra_show_menu, &ALGEBRA_LEVEL2, nullptr, 0
};
const alicee::MenuItem alicee::ALGEBRA_LEVEL3_3{
        "Хочу научиться делить!", MenuFunctions::algebra_show_menu, &ALGEBRA_LEVEL2, nullptr, 0
};
const alicee::MenuItem alicee::ALGEBRA_LEVEL3_4{
        "Хочу научиться умножать!", MenuFunctions::algebra_show_menu, &ALGEBRA_LEVEL2, nullptr, 0
};


const alicee::MenuItem alicee::MATHAN_LEVEL3_1{
        "Хочу изучить дифференциальное исчисление!", MenuFunctions::mathan_show_menu, &MATHAN_LEVEL2, nullptr, 0
};
const alicee::MenuItem alicee::MATHAN_LEVEL3_2{
        "Хочу изучить интегральное исчисление!", MenuFunctions::mathan_show_menu, &MATHAN_LEVEL2, nullptr, 0
};
