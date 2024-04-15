//
// Created by alicee on 10.03.2024.
//
#include "iostream"
#include "long_number.hpp"

using namespace std;
typedef ASulimov::LongNumber ln;

// ‼️ leaks -atExit -- build_ninja/SCL/Long_Numbers/main
// Вставить в терминал и проверить скомпилированный файл на утечки

int main(){

    ASulimov::LongNumber one_v1 = "1217654761782467816248764861284618724";
    ASulimov::LongNumber one_v2 = "12176561264871624861284681264876178264871627844761782467816248764861284618724";
    for(int i = 0; i < 2000; i++){
        ASulimov::LongNumber res = one_v1*one_v2;
        one_v2 = one_v2 - 1;
    }

    ASulimov::LongNumber res = "0";
    for(int i = 0; i < 2000; i++){x
        res = (res + one_v1);
        res = (res + one_v2);
        one_v2 = one_v2 - 1;
    }
    cout << "Operations Completed!" << endl;

    /*
    //cout << " | " << (one_v1 == ln("0")) << " | " << endl;
    //cout << " | " << (one_v2 == ln("0")) << " | " << endl;
    //cout << " | " << "6666126666666666666666660000000000000000000" << " | " << endl;
    //cout << " | v1 =  " << one_v1 << " | " << endl;
    //cout << " | v2 =  " << one_v2 << " | " << endl;
    //cout << " | ln(0) =  " << ln("0") << " | " << endl;
    //IBusko::LongNumber one_v3 = IBusko::LongNumber("1223");
    //cout << one_v1 << endl << one_v2 <<  endl;
    * test test/
    return  0;

}
