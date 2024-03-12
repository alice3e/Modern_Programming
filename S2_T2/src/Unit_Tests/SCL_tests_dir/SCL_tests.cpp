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

//Tests of "=="
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

//Tests of ">"
class IsMoreFixture : public testing::Test {
public:
    IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
    IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
    IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
};

TEST_F(IsMoreFixture, more) {
    ASSERT_TRUE(twelve > one_v1)
                                << "Проверка " << twelve << " > " << one_v1;
}

TEST_F(IsMoreFixture, less) {
    ASSERT_FALSE(one_v1 > twelve)
                                << "Проверка " << one_v1 << " > " << twelve;
}

TEST_F(IsMoreFixture, equal) {
    ASSERT_FALSE(one_v1 > one_v2)
                                << "Проверка " << one_v1 << " > " << one_v2;
}

TEST_F(IsMoreFixture, less_negative_var) {
    ASSERT_FALSE(negative_twelve > one_v1)
                                << "Проверка " << negative_twelve << " > " << one_v1;
}

TEST_F(IsMoreFixture, equal_negative_var) {
    ASSERT_TRUE(one_v1 > negative_one)
                                << "Проверка " << one_v1 << " > " << negative_one;
}

//Tests of "<"
class IsLessFixture : public testing::Test {
public:
    IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
    IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
    IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
};

TEST_F(IsLessFixture, less) {
    ASSERT_TRUE(one_v1 < twelve)
                                << "Проверка " << one_v1 << " < " << twelve;
}

TEST_F(IsLessFixture, more) {
    ASSERT_FALSE(twelve < one_v1)
                                << "Проверка " << twelve << " < " << one_v1;
}

TEST_F(IsLessFixture, equal) {
    ASSERT_FALSE(one_v1 < one_v2)
                                << "Проверка " << one_v1 << " < " << one_v2;
}

TEST_F(IsLessFixture, less_negative_var) {
    ASSERT_TRUE(negative_twelve < one_v1)
                                << "Проверка " << negative_twelve << " < " << one_v1;
}

TEST_F(IsLessFixture, equal_negative_var) {
    ASSERT_FALSE(negative_one > one_v1)
                                << "Проверка " << negative_one << " < " << one_v1;
}

//Tests of "+"
class Addition : public testing::Test {
public:
    IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
    IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
    IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
    IBusko::LongNumber big_num_v1 = IBusko::LongNumber("10000000000000000000");
    IBusko::LongNumber big_num_v2 = IBusko::LongNumber("6666666666666666666666");
};

TEST_F(Addition, big_nums) {
    IBusko::LongNumber ans = IBusko::LongNumber("6676666666666666666666");
    IBusko::LongNumber res;
    res = big_num_v1 + big_num_v2;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << big_num_v1 << " + " << big_num_v2;
}

TEST_F(Addition, small_nums) {
    IBusko::LongNumber ans = IBusko::LongNumber("13");
    IBusko::LongNumber res;
    res = twelve + one_v1;
    ASSERT_EQ(res, ans) << "Неправильно посчитано: " << twelve << " + " << one_v1;
}


TEST_F(Addition, negative_nums) {
    IBusko::LongNumber ans = IBusko::LongNumber("-13");
    IBusko::LongNumber res;
    res = negative_one + negative_twelve;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << negative_one << " + " << negative_twelve;
}

//Tests of "-"
class Subtraction : public testing::Test {
public:
    IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
    IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
    IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
    IBusko::LongNumber big_num_v1 = IBusko::LongNumber("10000000000000000000");
    IBusko::LongNumber big_num_v2 = IBusko::LongNumber("6666666666666666666666");
    IBusko::LongNumber null = IBusko::LongNumber("0");
};

TEST_F(Subtraction, little_nums) {
    IBusko::LongNumber ans = IBusko::LongNumber("11");
    IBusko::LongNumber res;
    res = twelve - one_v1;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << twelve << " - " << one_v1;
}

TEST_F(Subtraction, null) {
    IBusko::LongNumber ans = IBusko::LongNumber("0");
    IBusko::LongNumber res;
    res = one_v1 - one_v2;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << one_v1 << " - " << one_v2;
}

TEST_F(Subtraction, big_nums) {
    IBusko::LongNumber ans = IBusko::LongNumber("6656666666666666666666");
    IBusko::LongNumber res;
    res = big_num_v2 - big_num_v1;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << big_num_v2 << " - " << big_num_v1;
}

TEST_F(Subtraction, negative_ans) {
    IBusko::LongNumber ans = IBusko::LongNumber("-6656666666666666666666");
    IBusko::LongNumber res;
    res = big_num_v1 - big_num_v2;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << big_num_v1 << " - " << big_num_v2;
}

//Tests of "*"
class Multiplication : public testing::Test {
public:
    IBusko::LongNumber null = IBusko::LongNumber("0");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
    IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
    IBusko::LongNumber big_num_v1 = IBusko::LongNumber("10000000000000000000");
    IBusko::LongNumber big_num_v2 = IBusko::LongNumber("6666666666666666666666");
};

TEST_F(Multiplication, little_nums) {
    IBusko::LongNumber multiplier = IBusko::LongNumber("2");
    IBusko::LongNumber ans = IBusko::LongNumber("24");
    IBusko::LongNumber res;
    res = twelve * multiplier;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << twelve << " * " << multiplier;
}

TEST_F(Multiplication, big_nums) {
    IBusko::LongNumber ans = IBusko::LongNumber("66666666666666666666660000000000000000000");
    IBusko::LongNumber res;
    res = big_num_v1 * big_num_v2;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << big_num_v1 << " * " << big_num_v2;
}

TEST_F(Multiplication, check_one) {
    IBusko::LongNumber multiplier = IBusko::LongNumber("1");
    IBusko::LongNumber ans = IBusko::LongNumber("12");
    IBusko::LongNumber res;
    res = twelve * multiplier;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << twelve << " * " << multiplier;
}

TEST_F(Multiplication, two_nulls) {
    IBusko::LongNumber ans = IBusko::LongNumber("0");
    IBusko::LongNumber res;
    res = null * null;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << null << " * " << null;
}

TEST_F(Multiplication, positive_null) {
    IBusko::LongNumber ans = IBusko::LongNumber("0");
    IBusko::LongNumber res;
    res = big_num_v1 * null;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << big_num_v1 << " * " << null;
}

TEST_F(Multiplication, negative_null) {
    IBusko::LongNumber ans = IBusko::LongNumber("0");
    IBusko::LongNumber res;
    res = negative_twelve * null;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << negative_twelve << " * " << null;
}

TEST_F(Multiplication, negative_positive) {
    IBusko::LongNumber ans = IBusko::LongNumber("-120000000000000000000");
    IBusko::LongNumber res;
    res = negative_twelve * big_num_v1;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << negative_twelve << " * " << big_num_v1;
}

TEST_F(Multiplication, negative_negative) {
    IBusko::LongNumber ans = IBusko::LongNumber("12");
    IBusko::LongNumber res;
    res = negative_twelve * negative_one;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << negative_twelve << " * " << negative_one;
}

//Testf of "/"
class Division : public testing::Test {
public:
    IBusko::LongNumber one = IBusko::LongNumber("1");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
    IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
};


TEST_F(Division, without_reminder) {
    IBusko::LongNumber divider = IBusko::LongNumber("2");
    IBusko::LongNumber ans = IBusko::LongNumber("6");
    IBusko::LongNumber res;
    res = twelve / divider;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << twelve << " / " << divider;
}

TEST_F(Division, with_reminder) {
    IBusko::LongNumber divider = IBusko::LongNumber("5");
    IBusko::LongNumber ans = IBusko::LongNumber("2");
    IBusko::LongNumber res;
    res = twelve / divider;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << twelve << " / " << divider;
}

TEST_F(Division, negative_without_reminder) {
    IBusko::LongNumber divider = IBusko::LongNumber("-2");
    IBusko::LongNumber ans = IBusko::LongNumber("-6");
    IBusko::LongNumber res;
    res = twelve / divider;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << twelve << " / " << divider;
}

TEST_F(Division, negative_with_reminder) {
    IBusko::LongNumber divider = IBusko::LongNumber("-5");
    IBusko::LongNumber ans = IBusko::LongNumber("-2");
    IBusko::LongNumber res;
    res = twelve / divider;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << twelve << " / " << divider;
}

TEST_F(Division, check_one) {
    IBusko::LongNumber divider = one;
    IBusko::LongNumber ans = IBusko::LongNumber("12");
    IBusko::LongNumber res;
    res = twelve / divider;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << twelve << " / " << divider;
}

//Tests of "%"
class Remainder : public testing::Test {
public:
    IBusko::LongNumber null = IBusko::LongNumber("0");
    IBusko::LongNumber twelve = IBusko::LongNumber("12");
    IBusko::LongNumber five = IBusko::LongNumber("5");
    IBusko::LongNumber negative_twelve = IBusko::LongNumber("-12");
    IBusko::LongNumber negative_five = IBusko::LongNumber("-5");
};

TEST_F(Remainder, positive_positive) {
    IBusko::LongNumber ans = IBusko::LongNumber("2");
    IBusko::LongNumber res;
    res = twelve % five;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << twelve << " % " << five;
}

TEST_F(Remainder, positive_negative) {
    IBusko::LongNumber ans = IBusko::LongNumber("3");
    IBusko::LongNumber res;
    res = negative_twelve % five;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << negative_twelve << " % " << five;
}

TEST_F(Remainder, negative_negative) {
    IBusko::LongNumber ans = IBusko::LongNumber("3");
    IBusko::LongNumber res;
    res = negative_twelve % negative_five;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << negative_twelve << " % " << negative_five;
}

TEST_F(Remainder, check_null) {
    IBusko::LongNumber ans = IBusko::LongNumber("0");
    IBusko::LongNumber res;
    res = null % negative_twelve;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << null << " % " << negative_twelve;
}

TEST_F(Remainder, same_nums) {
    IBusko::LongNumber ans = IBusko::LongNumber("0");
    IBusko::LongNumber res;
    res = twelve % twelve;
    ASSERT_EQ(res, ans)
                                << "Неправильно посчитано: " << twelve << " % " << twelve;
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
