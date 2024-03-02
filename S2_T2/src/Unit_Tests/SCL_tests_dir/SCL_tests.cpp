//
// Created by alicee on 10.03.2024.
//
#include <gtest/gtest.h>

#include "long_number.hpp"

TEST(get_digits_number, check_positive) {
IBusko::LongNumber x("12345");
ASSERT_EQ(5, x.get_digits_number())
<< "Неправильно подсчитано количество разрядов в числе " << x;
}

TEST(get_digits_number, check_negative) {
IBusko::LongNumber x("-1");
ASSERT_EQ(1, x.get_digits_number())
<< "Неправильно подсчитано количество разрядов в числе " << x;
}

class EqualityFixture : public testing::Test {
public:
    IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
    IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
};

TEST_F(EqualityFixture, equal) {
ASSERT_TRUE(one_v1 == one_v2) << "Проверка " << one_v1 << " == " << one_v2;
}

TEST_F(EqualityFixture, not_equal) {
ASSERT_FALSE(one_v1 == twelve) << "Проверка " << one_v1 << " == " << twelve;
}

TEST_F(EqualityFixture, not_equal_negative_var) {
ASSERT_FALSE(one_v1 == negative_one)
<< "Проверка " << one_v1 << " == " << negative_one;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}