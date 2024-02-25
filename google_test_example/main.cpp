#include <code_example.hpp>


int main() {
    // типо какой-то код кторый использует нашу библиотеку some_lib

    std::vector <int> original = some_namespace::rand_vec(10);
    std::vector <int> srt = some_namespace::bubble(original);

    if(some_namespace::check_f){ std::cout << "Сортировка сработала верно!" << std::endl; }
    else{ std::cout << "Ошибка в алгоритме(" << std::endl; }

    return 0;
}