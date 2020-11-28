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
#include "../composite/header/op.hpp"
#include "../composite/header/add.hpp"
#include <cstring>

void deleteMemory(char**, size_t);

TEST(ClassAdditionTest, AddEvaluateNonZero) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="+"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="2"; 
  input[3] = new char[strlen(fourth) + 1];
  strcpy(input[3], fourth);

  Base* decimal_one = new Op(1);
  Base* decimal_two = new Op(2);
  Base* expression = new Add(decimal_one, decimal_two);

  EXPECT_EQ(test->parse(input, 4)->evaluate(), expression->evaluate());
  deleteMemory(input, 4); 
}

void deleteMemory(char** str, size_t n) {
  for(int i = 0; i < n; i++) {
    delete[] str[i];
  }

  delete[] str;

}
