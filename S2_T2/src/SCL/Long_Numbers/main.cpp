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
    IBusko::LongNumber one_v1 = "11321231231212312312331321232";
    IBusko::LongNumber one_v2 = "51112312323112312312312323123";

    cout << " ‼️‼️| " << (one_v1 + one_v2) << " | ‼️‼️" << endl;

    //cout << " | " << (one_v1 == ln("0")) << " | " << endl;
    //cout << " | " << (one_v2 == ln("0")) << " | " << endl;
    //cout << " | " << "66666666666666666666660000000000000000000" << " | " << endl;
    //cout << " | v1 =  " << one_v1 << " | " << endl;
    //cout << " | v2 =  " << one_v2 << " | " << endl;
    //cout << " | ln(0) =  " << ln("0") << " | " << endl;
    //IBusko::LongNumber one_v3 = IBusko::LongNumber("1223");
    //cout << (one_v1 == one_v3) << endl;
    //cout << one_v1 << endl << one_v2 <<  endl;

    return  0;

}

//std::cout << length_ << std::endl;