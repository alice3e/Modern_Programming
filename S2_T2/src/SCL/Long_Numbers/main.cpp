//
// Created by alicee on 10.03.2024.
//
#include "iostream"
#include "long_number.hpp"

using namespace std;
typedef IBusko::LongNumber ln;

int main(){
    IBusko::LongNumber one_v1 = "123";
    cout << " | " << one_v1 << " | " << endl;

    IBusko::LongNumber one_v2 = 13;
    cout << " | " << one_v2 << " | " << endl;
    //one_v1 = IBusko::LongNumber("1223");
    //IBusko::LongNumber one_v2 = IBusko::LongNumber("1223");
    //cout << (one_v1 == one_v2) << endl;
    //cout << one_v1 << endl << one_v2 <<  endl;

    return  0;

}

//std::cout << length_ << std::endl;