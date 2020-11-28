#include "gtest/gtest.h"
#include "../Factory.hpp"
#include "../composite/header/op.hpp"
#include "../composite/header/add.hpp"
#include <cstring>

//1 + 0
TEST(ClassAdditionTest, AddEvaluateZero) {
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

  char fourth[2] ="0"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  Base* decimal_one = new Op(1);
  Base* decimal_zero = new Op(0);

  Base* additionComposite = new Add(decimal_one, decimal_zero);

  EXPECT_EQ(test->parse(input, 4)->evaluate(), additionComposite->evaluate());
}

//1 + 0 string
TEST(ClassAdditionTest, AddEvaluateZeroString) {
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

  char fourth[2] ="0"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  Base* decimal_one = new Op(1);
  Base* decimal_zero = new Op(0);

  Base* additionComposite = new Add(decimal_one, decimal_zero);

  EXPECT_EQ(test->parse(input, 4)->stringify(), additionComposite->stringify());
}

//1 + 2
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
}

//1 + 1 + 1 + 1
TEST(ClassAdditionTest, AddMultipleEvaluateNonZero) {
  Factory* test = new Factory();
  char** input = new char*[8];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="+"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="1"; 
  input[3] = new char[strlen(fourth) + 1];
  strcpy(input[3], fourth);

  char fifth[2] ="+"; 
  input[4] = new char[strlen(fifth) + 1];
  strcpy(input[4], fifth);

  char sixth[2] ="1"; 
  input[5] = new char[strlen(sixth) + 1];
  strcpy(input[5], sixth);

  char seventh[2] ="+"; 
  input[6] = new char[strlen(seventh) + 1];
  strcpy(input[6], seventh);

  char eigth[2] ="1"; 
  input[7] = new char[strlen(eigth) + 1];
  strcpy(input[7], eigth);

  Base* decimal_one = new Op(1);
  Base* decimal_two = new Op(1);
  Base* expression_one = new Add(decimal_one, decimal_two);

  Base* decimal_three = new Op(1);
  Base* decimal_four = new Op(1);
  Base* expression_two = new Add(decimal_three, decimal_four);

  Base* decimal_five = new Op(1);

  Base* expression_three = new Add(expression_two, decimal_five);

  EXPECT_EQ(test->parse(input, 7)->evaluate(), expression_three->evaluate()); 
}

// 1 +
TEST(ClassAdditionTest, AddInvalidEndWithOperator) {
  Factory* test = new Factory();
  char** input = new char*[3];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="+"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  EXPECT_TRUE(test->parse(input, 3) == nullptr);
}

TEST(ClassAdditionTest, AddInvalidStartWithOperator) {
  Factory* test = new Factory();
  char** input = new char*[3];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="+"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="1"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  EXPECT_TRUE(test->parse(input, 3) == nullptr);
}

// 1a +
TEST(ClassAdditionTest, AddMixedOperand) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[3] ="1a"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="+"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="1"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  EXPECT_TRUE(test->parse(input, 4) == nullptr);
}

// a
TEST(ClassAdditionTest, AddInvalidOperand) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="a"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="+"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="1"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  EXPECT_TRUE(test->parse(input, 4) == nullptr);
}



