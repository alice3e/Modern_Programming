//intr_sort.cpp
#include "intr_sort.h"

void IntrSort::srt(std::vector <int> &v,std::vector <int> &ans){ // TODO : make it work!
    int sz = v.size();
    ans.push_back(v[0]);
    for(int i = 1;i<sz;i++){
        int &el = v[i];
        if((i+1)%2==0){ //ИНДЕКСАЦИЯ С 1 НАЧИНАЕТСЯ
            ans.push_back(el);
            if (el < ans[i-1]){
                std::swap(ans[i],ans[i-1]);
            }
        }
        else{
            ans.push_back(el);
            if(el > ans[i-1]){
                std::swap(ans[i],ans[i-1]);
            }
        }
    }
}