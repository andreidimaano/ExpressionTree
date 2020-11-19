#include "gtest/gtest.h"

// #include"op_test.hpp"
// #include "class_sub_test.hpp"
// #include "rand_test.hpp"
// #include "div_test.hpp"
#include "../header/add.hpp"
#include "../header/op.hpp"
// #include "mult_test.hpp"
// #include "pow_test.hpp"

TEST(ClassAdditionTest, AddEvaluateNonZero) {
	Base* left = new Op(10.0);
	Base* right = new Op(20.0);
	Base* test = new Add(left, right);
	EXPECT_DOUBLE_EQ(test->evaluate(),30.0);
}

//1 pos, 1 neg
TEST(ClassAdditionTest, AddEvaluatePosNeg) {
    Base* left = new Op(-10.0);
    Base* right = new Op(20.0);
    Base* test = new Add(left, right);
    EXPECT_DOUBLE_EQ(test->evaluate(), 10.0);
}

TEST(ClassAdditionTest, AddEvaluatePosNegString) {
    Base* left = new Op(-10.0);
    Base* right = new Op(20.0);
    Base* test = new Add(left, right);
    std::string str = "-10.000000 + 20.000000";
    EXPECT_EQ(test->stringify(), str);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
