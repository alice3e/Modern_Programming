#include <clocale>
#include <iostream>

#include "menu.h"
#include "menu_elements.h"
#include "element_functions.h"


int main() {
    std::setlocale(LC_ALL, "");
    std::cout << "Добро Пожаловать в программу обучения балбесов!\n";
    const alicee::MenuItem *current = &alicee::MAIN_LEVEL0;

    do {
        current = current->itemfunction(current); // Выглядит максимально криво.
        // если писать через класс, то можно просто использовать self и не передавать current в func()
    } while (true);

    return 0;
}