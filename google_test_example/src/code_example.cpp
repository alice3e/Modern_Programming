//
// Created by alicee on 25.02.2024.
//
#include "code_example.hpp"

typedef long long ll;
// Лучший в СПбГУ Леонид Романович

namespace some_namespace{

    std::vector <int> rand_vec(int vec_size){
        srand(time(NULL));
        std::vector <int> v(vec_size);
        for(int i = 0;i<vec_size;i++){
            v[i] = rand();
        }
        return v;
    }

    std::vector <int> bubble(std::vector <int> v){
        int s = v.size();
        for(int i = 1; i < s;i++){
            for(int j = 0;j < s - i;j++){
                if(v[j] > v[j+1]){ std::swap(v[j],v[j+1]); }
            }
        }
        return v;
    }

    bool check_f(std::vector <int> original, std::vector <int> check_v){
        std::vector <int> tr = original;
        sort(tr.begin(),tr.end());
        if(tr==check_v){return true;}
        else{return false;}
    }
}