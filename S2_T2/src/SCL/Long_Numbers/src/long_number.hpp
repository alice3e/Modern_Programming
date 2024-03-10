//
// Created by alicee on 10.03.2024.
//
#pragma once

#include <iostream>
#include <string>


namespace IBusko {
    class LongNumber {
        static const char END = '\0';
        static const char MINUS = '-';
        static const int NEGATIVE = -1;
        static const int POSITIVE = 1;

        int *numbers_;
        int length_;
        int sign_;

    public:
        LongNumber(); // Конструктор по умолчанию //✅
        LongNumber(const char *const str); // для "строки" //✅
        LongNumber(const int x); // для INT //✅
        LongNumber(const LongNumber &x); // конструктор копирования //✅
        LongNumber(LongNumber &&x); // конструктор перемещения //✅

        ~LongNumber(); // деструктор //✅

        LongNumber &operator=(const char *const str);//✅
        LongNumber &operator=(const int x);//✅
        LongNumber &operator=(const LongNumber &x); // оператор присваивания копированием//✅
        LongNumber &operator=(LongNumber &&x); // оператор присваивания перемещения//✅

        bool operator==(const LongNumber &x) const;//✅
        bool operator!=(const LongNumber &x) const;//✅
        bool operator>(const LongNumber &x) const;
        bool operator<(const LongNumber &x) const;

        LongNumber operator+(const LongNumber &x);

        LongNumber operator-(const LongNumber &x);

        LongNumber operator*(const LongNumber &x);

        LongNumber operator/(const LongNumber &x);

        LongNumber operator%(const LongNumber &x);

        int get_digits_number() const;//✅
        bool is_positive() const;//✅

        friend std::ostream &operator<<(std::ostream &os, const LongNumber &x);//✅

    private:
        int get_length(const char *const str) const;
    };
}