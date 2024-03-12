//
// Created by alicee on 10.03.2024.
//
#include "iostream"
#include "long_number.hpp"

using namespace std;
typedef IBusko::LongNumber ln;

// ‼️ leaks -atExit -- build_ninja/SCL/Long_Numbers/main
// Вставить в терминал и проверить скомпилированный файл на утечки

int main(){
    IBusko::LongNumber one_v1 = 1;
    IBusko::LongNumber one_v2 = 1;

    cout << " | " << (one_v1 + one_v2) << " | " << endl;
    //cout << " | " << one_v2 << " | " << endl;
    //cout << " | " << one_v1 << " | " << endl;
    //IBusko::LongNumber one_v3 = IBusko::LongNumber("1223");
    //cout << (one_v1 == one_v3) << endl;
    //cout << one_v1 << endl << one_v2 <<  endl;

    return  0;

}

//std::cout << length_ << std::endl;