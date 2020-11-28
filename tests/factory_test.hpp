#include "gtest/gtest.h"

// #include"op_test.hpp"
// #include "class_sub_test.hpp"
// #include "rand_test.hpp"
// #include "div_test.hpp"
// #include "../header/add.hpp"
// #include "../header/op.hpp"
// #include "mult_test.hpp"
// #include "pow_test.hpp"
#include "../Factory.hpp"

TEST(ClassAdditionTest, AddEvaluateNonZero) {
	Factory* test = new Factory();
  char* equation = "1+2";
  char** input = &equation;

  
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
