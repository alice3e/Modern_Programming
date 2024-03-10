//
// Created by alicee on 10.03.2024.
//
#include "iostream"
#include "long_number.hpp"

using namespace std;
typedef IBusko::LongNumber ln;

int main(){
    ln b = "-12345";
    ln a = ln(123123);

    cout << "|| ";
    cout << a << endl;
    cout << a.get_digits_number() << endl;
    cout << "END!" << endl;
    return  0;

}

//std::cout << length_ << std::endl;