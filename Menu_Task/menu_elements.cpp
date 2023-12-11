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
        "Главное Меню","", MenuFunctions::show_element_menu, nullptr, main_children::children, 1
};

const alicee::MenuItem alicee::SUBJECT_CHOICE_LEVEL1{
        "Меню программ обучения","", MenuFunctions::show_element_menu, &MAIN_LEVEL0, main_education_children::children, 2
};

const alicee::MenuItem alicee::ALGEBRA_LEVEL2{
        "Меню изучения Алгебры","", MenuFunctions::show_element_menu, &SUBJECT_CHOICE_LEVEL1, algebra_children::children, 4
};

const alicee::MenuItem alicee::MATHAN_LEVEL2{
        "Меню изучения МатАнализа","", MenuFunctions::show_element_menu, &SUBJECT_CHOICE_LEVEL1, mathan_children::children, 2
};


const alicee::MenuItem alicee::ALGEBRA_LEVEL3_1{
        "Хочу научиться складывать!","https://resh.edu.ru/subject/lesson/6865/conspect/236927/",
        MenuFunctions::show_element_with_link_menu, &ALGEBRA_LEVEL2, nullptr, 0
};
const alicee::MenuItem alicee::ALGEBRA_LEVEL3_2{
        "Хочу научиться вычитать!","https://skysmart.ru/articles/mathematic/vychitanie-stolbikom",
        MenuFunctions::show_element_with_link_menu, &ALGEBRA_LEVEL2, nullptr, 0
};
const alicee::MenuItem alicee::ALGEBRA_LEVEL3_3{
        "Хочу научиться делить!","http://spacemath.xyz/delenie/",
        MenuFunctions::show_element_with_link_menu, &ALGEBRA_LEVEL2, nullptr, 0
};
const alicee::MenuItem alicee::ALGEBRA_LEVEL3_4{
        "Хочу научиться умножать!","https://skysmart.ru/articles/mathematic/umnozhenie-v-stolbik",
        MenuFunctions::show_element_with_link_menu, &ALGEBRA_LEVEL2, nullptr, 0
};


const alicee::MenuItem alicee::MATHAN_LEVEL3_1{
        "Хочу изучить дифференциальное исчисление!","https://hti.urfu.ru/fileadmin/user_upload/site_15078/dokumenty/zaochniki/2_matem_analiz_funkcii_odnoi_peremennoi.pdf",
        MenuFunctions::show_element_with_link_menu, &MATHAN_LEVEL2, nullptr, 0
};
const alicee::MenuItem alicee::MATHAN_LEVEL3_2{
        "Хочу изучить интегральное исчисление!","https://www.booksite.ru/fulltext/1/001/008/055/368.htm",
        MenuFunctions::show_element_with_link_menu, &MATHAN_LEVEL2, nullptr, 0
};
