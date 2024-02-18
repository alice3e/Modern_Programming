//
// Created by alicee on 18.02.2024.
//
//Файл, из которого рассматривали примеры базовой теории с 16-ой группой
#include <clocale>
#include <iostream>

void func(wchar_t msg[], const wchar_t const_msg[], const wchar_t* const super_const_msg);

int main() {
    setlocale(LC_ALL, "Russian");

    const char space = ' ';

    {
        std::wcout << L"Деление чисел" << std::endl;
        std::cout << "5 / 9 = " << 5 / 9 << std::endl;
        std::cout << "5.0 / 9 = " << 5.0 / 9 << std::endl;

        int a = 1;
        int b = 5;
        std::cout << "a / b = " << a / b << std::endl;

        std::cout << std::endl << std::endl;
    }

    {
        std::wcout << L"Указатели. Основа" << std::endl;
        int x = 5;
        int* xptr = &x;
        std::cout << "xptr = " << xptr << "; *xptr = " << *xptr << std::endl;

        int* yptr = xptr;
        *yptr = 10;
        std::cout << "x = " << x << "; *xptr = " << *xptr << std::endl;
        std::cout << std::endl;

        std::wcout << L"Приоритет операций" << std::endl;
        int y1 = *xptr + 1;
        int y2 = *(xptr + 1);
        std::cout << "y1 = " << y1 << "; y2 = " << y2 << std::endl;

        *xptr += 1;
        std::cout << "\"*xptr += 1\" = " << *xptr << std::endl;
        std::cout << std::endl;

        std::wcout << L"Префиксный и постфиксный инкремент" << std::endl;
        *xptr = 5;
        std::cout << "x = " << x << std::endl;
        std::cout << "++x = " << ++x << std::endl;
        std::cout << "x++ = " << x++ << std::endl;

        std::cout << "++*xptr = " << ++ * xptr << std::endl;
        //std::cout << "*xptr++ = " << *xptr++ << std::endl;
        std::cout << "(*xptr)++ = " << (*xptr)++ << std::endl;

        std::cout << std::endl << std::endl;
    }

    {
        int a = 1, b = 2;
        std::swap(a, b);
        std::cout << "a = " << a << "; b = " << b << std::endl;
        std::cout << std::endl;

        std::wcout << L"Указатели и массивы" << std::endl;

        int arr[3] = { 1, 10, 20 };
        std::wcout << L"Элементы массива:";
        for (int x : arr) {
            std::cout << space << x;
        }
        std::cout << std::endl;

        int* ptr_arr = &arr[0];

        std::cout << "sizeof(arr) = " << sizeof(arr) << std::endl;
        std::cout << "sizeof(ptr_arr) = " << sizeof(ptr_arr) << std::endl;
        std::cout << std::endl;

        std::wcout << L"Вспоминаем что такое постфиксный инкремент" << std::endl;
        std::cout << "*ptr_arr++ = " << *ptr_arr++ << std::endl;
        std::cout << "++*ptr_arr = " << ++*ptr_arr << std::endl;
        std::cout << "*++ptr_arr = " << *++ptr_arr << std::endl;

        std::cout << "*(ptr_arr + 1) = " << *(ptr_arr + 1) << std::endl;
        std::cout << "ptr_arr - &arr[0] = " << ptr_arr - &arr[0] << std::endl;
        //*(ptr_arr += 1) = 0;

        std::cout << std::endl << std::endl;
    }

    {
        std::wcout << L"Имя массива НЕ является переменной!!!" << std::endl;
        std::wcout << L"А указатель, выступающий в роли имени массива является переменной." << std::endl;
        std::cout << std::endl;

        int arr[] = {1, 2, 3, 4, 5, 6};
        std::wcout << L"Почему индексация у массивов начинается с 0?" << std::endl;
        std::cout << std::endl;

        std::wcout << L"Хитромудрёный пример:" << std::endl;
        int example_1 = 3[arr - 1] - arr[3] + (arr - 1)[5];
        std::cout << "3[arr - 1] - arr[3] + (arr - 1)[5] = " << example_1 << std::endl;

        std::cout << std::endl << std::endl;
    }

    {
        wchar_t msg[] = L"Я массив! А тот, что в следующей строке, - всего лишь указатель на меня.";
        const wchar_t* ptr_msg = L"Увы, я всего лишь указатель. И делайте со мной любые (допустимые) операции :(";
    }

    {
        wchar_t msg[] = L"Мне можно менять только значения!";
        const wchar_t const_value_msg[] = L"А меня вообще никак нельзя менять!";

        msg[0] = L'Б';
        //const_value_msg[0] = L'Б';

        //const_value_msg = msg;
        //msg = const_value_msg;
    }

    {
        //wchar_t* error_msg = L"Меня константу хотят присвоить обычной переменной!";
        const wchar_t* const_value_msg = L"Мне нельзя менять значения, но можно присвоить адрес на другую строку!";
        const wchar_t* const super_const_msg = L"А меня вообще никак нельзя менять!";

        //const_value_msg[0] = L'Б';
        const_value_msg = super_const_msg;
        //super_const_msg = const_value_msg;
    }

    {
        wchar_t msg[] = L"Я массив, но в функцию пойду как указатель на первый элемент строки. У меня можно все менять :(";
        const wchar_t const_msg[] = L"Я тоже в функцию пойду как указатель на первый элемент строки :(, "
                                    "но с неизменяемыми значениями! :)";
        const wchar_t* const super_const_msg = L"А я неизменяемый указатель на неизменяемые данные! Ха! Ха!";
        func(msg, const_msg, super_const_msg);
    }

    {
        std::wcout << L"Массив единиц элегантно превращается в: ";
        char carr[] = { 1,1,1,1, 1,1,1,1, 1,1,1,1 };
        *((int*)carr + 2) = 0;
        int i = 0;
        for (int x : carr) {
            std::cout << space << x;
            i++;
        }
        std::wcout << "; i = " << i << std::endl;

        std::cout << std::endl << std::endl;
    }

    return 0;
}

void func(wchar_t msg[], const wchar_t const_msg[], const wchar_t* const super_const_msg) {

}