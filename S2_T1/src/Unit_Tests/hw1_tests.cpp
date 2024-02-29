#include <gtest/gtest.h>
#include "intr_sort.h"

TEST(NAME_OF_GROUP_TEST, test1){
std::vector <int> original{};
std::vector <int> copy_of_original_for_std = original;
original = IntrSort::srt(original);
std::sort(copy_of_original_for_std.begin(),copy_of_original_for_std.end());
ASSERT_EQ(original,copy_of_original_for_std) << "test 1 (zero size) wrong!";
}
