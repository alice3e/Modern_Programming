#include <gtest/gtest.h>
#include "intr_sort.h"

// LOAD MAIN CMAKE FILE (IN SRC DIR)

TEST(Bubble_Tests, test1){
std::vector <int> original{1};
std::vector<int> answ;
IntrSort::srt(answ,original);
std::sort(original.begin(),original.end());
ASSERT_EQ(answ,original) << "test 1 (1 element size) wrong!";
}


TEST(Bubble_Tests, test2){
    std::vector <int> original{3,2,1};
    std::vector<int> answ;
    IntrSort::srt(answ,original);
    std::sort(original.begin(),original.end());
    ASSERT_EQ(answ,original) << "test 2 (3 element size) wrong!";
}

TEST(Bubble_Tests, test3){
    std::vector <int> original{};
    std::vector<int> answ;
    IntrSort::srt(answ,original);
    // std::sort(original.begin(),original.end());
    ASSERT_EQ(answ, original) << "test 3 (zero size) wrong!";
}

TEST(Bubble_Tests, WRONG_TEST){ // SHOULD GIVE AN ERROR
    std::vector <int> original{1,2,5,-200,5,5,0,-100};
    std::vector<int> answ;
    IntrSort::srt(answ,original);
    std::sort(original.begin(),original.end());
    ASSERT_EQ(answ,original) << "test 4 (WRONG TEST) wrong!";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}