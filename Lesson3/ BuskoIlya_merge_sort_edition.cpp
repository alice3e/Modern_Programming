#include <iostream>
#include <random>

int* create_merge_array(int input_arr[], const int sz, const int p);
void init_arr(int arr[], const int sz, const int max_el_size);
void merge(int input_arr[], const int left, const int middle, const int right);
void merge_rec(int arr[], const int left, const int right);
void print_array(const wchar_t* const comment, int arr[], const int sz);

int main() {
    std::setlocale(LC_ALL, "Russian");

    const int arr_size = (int)1e3;
    const int max_el_size = (int)1e4;
    int arr[arr_size];
    init_arr(arr, arr_size, max_el_size);
    print_array(L"Был сгенерирован массив:", arr, arr_size);
    std::cout << std::endl;

    merge_rec(arr, 0, arr_size - 1);
    print_array(L"Массив после сортировки слиянием:", arr, arr_size);

    return 0;
}

int* create_merge_array(int input_arr[], const int sz, const int p) {
    int* result_arr = new int[sz + 1];

    for (int i = 0; i < sz; i++) {
        result_arr[i] = input_arr[p + i];
    }

    static const int INF = (int)1e10;
    result_arr[sz] = INF;

    return result_arr;
}

void init_arr(int arr[], const int sz, const int max_el_size) {
    std::mt19937 rnd(time(NULL));
    for (int i = 0; i < sz; i++) {
        arr[i] = rnd() % max_el_size;
    }
}

void merge(int input_arr[], const int left, const int middle, const int right) {
    const int arr1_size = middle - left + 1;
    const int arr2_size = right - middle;

    int* arr1 = create_merge_array(input_arr, arr1_size, left);
    int* arr2 = create_merge_array(input_arr, arr2_size, middle + 1);

    {
        int k = left, i = 0, j = 0;
        while (i < arr1_size && j < arr2_size) {
            if (arr1[i] < arr2[j]) {
                input_arr[k] = arr1[i];
                i++;
            }
            else {
                input_arr[k] = arr2[j];
                j++;
            }
            k++;
        }

        while (i < arr1_size) {
            input_arr[k] = arr1[i];
            i++;
            k++;
        }

        while (j < arr2_size) {
            input_arr[k] = arr2[j];
            j++;
            k++;
        }
    }

    delete[] arr1;
    delete[] arr2;
}

void merge_rec(int arr[], const int left, const int right) {
    if (left < right) {
        const int middle = (left + right) / 2;
        merge_rec(arr, left, middle);
        merge_rec(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void print_array(const wchar_t* const comment, int arr[], const int sz) {
    const char space = ' ';
    std::wcout << comment;
    for (int i = 0; i < sz; i++) {
        std::cout << space << arr[i];
    }
    std::cout << std::endl;
}
