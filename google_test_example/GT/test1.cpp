//
// Created by alicee on 25.02.2024.
//
#include <gtest/gtest.h>
#include "code_example.hpp"

TEST(NAME_OF_GROUP_TEST, test1){
    std::vector <int> original{};
    std::vector <int> copy_of_original_for_std = original;
    original = some_namespace::bubble(original);
    std::sort(copy_of_original_for_std.begin(),copy_of_original_for_std.end());
    ASSERT_EQ(original,copy_of_original_for_std) << "test 1 (zero size) wrong!";
}

TEST(NAME_OF_GROUP_TEST, test2){
    std::vector <int> original{1,2,3};
    std::vector <int> copy_of_original_for_std = original;
    original = some_namespace::bubble(original);
    std::sort(copy_of_original_for_std.begin(),copy_of_original_for_std.end());
    ASSERT_EQ(original,copy_of_original_for_std) << "test 1 (sorted vec) wrong!";
}

TEST(NAME_OF_GROUP_TEST, test3){
    // THIS TEST MUST GIVE AN ERROR!!!!
    std::vector <int> original{3,2,1};
    std::vector <int> copy_of_original_for_std = original;
    original = some_namespace::bubble(original);
    //std::sort(copy_of_original_for_std.begin(),copy_of_original_for_std.end()); - NO SORT!
    ASSERT_EQ(original,copy_of_original_for_std) << "test 3 (100% wrong test) wrong!";
}