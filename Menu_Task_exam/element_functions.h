#include <iostream>

#include "menu.h"
#pragma once

namespace menu_functions{

    const alicee::MenuItem *show_menu(const alicee::MenuItem *current);
    const alicee::MenuItem *program_exit(const alicee::MenuItem *current);
    const alicee::MenuItem *go_back(const alicee::MenuItem *current);
}