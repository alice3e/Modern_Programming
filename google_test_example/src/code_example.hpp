//
// Created by alicee on 25.02.2024.
//
#pragma once
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

namespace some_namespace {
     extern std::vector<int> rand_vec(int vec_size);

    extern std::vector<int> bubble(std::vector<int> v);

    extern bool check_f(std::vector<int> original, std::vector<int> check_v);
}