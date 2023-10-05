#include <iostream>
#include <random>

#define INF 10e9

void merger(int v[], int left, int middle, int right);
void merge_rec(int v[], int left, int right);
void rnd_arr(int a[], const int sz, int max_el_size);
void out(int v[],const int sz);

int main() {
    // CPP SPEEDUP
    setlocale(LC_ALL, "Russian");
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    // MAIN LOGIC
    const int size_a = 10e2; // sizeof(a) / sizeof(a[0])
    int a[size_a];
    rnd_arr(a, size_a, 10e3);
    merge_rec(a,0,size_a-1);
    out(a,size_a);
    return 0;
}

void rnd_arr(int a[], const int sz, int max_el_size) { // max_el_size = 1eX - максимальная длина элемента
    std::mt19937 rnd(time(NULL));
    for (int i = 0; i < sz; i++) {
        a[i] = (rnd() % max_el_size);
    }
}

void out(int v[],const int sz) {
    // не смог заставить работать с range-based for
    // тк массив передается как указатель.
    for(int i = 0; i < sz;i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void merger(int v[], int left, int middle, int right) {
    const int arr1_size = middle - left + 1;
    const int arr2_size = right - middle;

    int arr1[arr1_size + 1];
    int arr2[arr2_size + 1];
    arr1[arr1_size] = INF;
    arr2[arr2_size] = INF;
    for (int i = 0; i < arr1_size; i++) {
        arr1[i] = v[left + i];
    }
    for (int i = 0; i < arr2_size; i++) {
        arr2[i] = v[middle + i + 1];
    }

    //MERGING BACK
    int k = left, i = 0, j = 0; // k - main, i - arr1,j - arr2
    while (i < arr1_size && j < arr2_size) {
        if (arr1[i] < arr2[j]) {
            v[k] = arr1[i];
            i++;
        } else {
            v[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < arr1_size) {
        v[k] = arr1[i];
        i++;
        k++;
    }

    while (j < arr2_size) {
        v[k] = arr2[j];
        j++;
        k++;
    }
}

void merge_rec(int a[], int left, int right) {
    if (left < right) {
        const int middle = (left + right) / 2;
        merge_rec(a, left, middle);
        merge_rec(a, middle + 1, right);
        merger(a, left, middle, right);
    }
}