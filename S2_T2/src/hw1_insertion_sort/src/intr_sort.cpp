//intr_sort.cpp
#include "intr_sort.h"
#include <iostream>


void IntrSort::srt(std::vector<int> &ans, std::vector<int> &v) {
    int sz = v.size();
    if(sz == 0){ return ; }
    ans.push_back(v[0]);
    for (int i = 1; i < sz; i++) {
        int el = v[i];
        ans.push_back(el);
        int j = i;
        bool swapped = false;
        if (i % 2 == 1) {
            while (j > 0 && el < ans[j - 1]) {
                std::swap(ans[j], ans[j - 1]);
                j--;
                swapped = true;
            }
        }
        else {
            while (j > 0 && el > ans[j - 1]) {
                std::swap(ans[j], ans[j - 1]);
                j--;
                swapped = true;
            }
        }
        if (!swapped) {
            for (int k = i; k > 0; k--) {
                if (el < ans[k - 1]) {
                    std::swap(ans[k], ans[k - 1]);
                }
            }
        }
    }
}
