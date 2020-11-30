#include "gtest/gtest.h"
#include "../Factory.hpp"
#include "../composite/header/op.hpp"
#include "../composite/header/pow.hpp"
#include <cstring>

//1 ^ 0
TEST(ClassPowerTest, PowEvaluateZero) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[3] ="**"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="0"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  Base* decimal_one = new Op(1);
  Base* decimal_zero = new Op(0);

  Base* PowerComposite = new Pow(decimal_one, decimal_zero);

  EXPECT_EQ(test->parse(input, 4)->evaluate(), PowerComposite->evaluate());
}

// //1 ^ 1 ^ 1 ^ 1 string
TEST(ClassPowerTest, PowEvaluateZeroString) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[3] ="**"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="0"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  Base* decimal_one = new Op(1);
  Base* decimal_zero = new Op(0);

  Base* PowerComposite = new Pow(decimal_one, decimal_zero);

  EXPECT_EQ(test->parse(input, 4)->stringify(), PowerComposite->stringify());
}

// //1 ^ 2
TEST(ClassPowerTest, PowEvaluateNonZero) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[3] ="**"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="2"; 
  input[3] = new char[strlen(fourth) + 1];
  strcpy(input[3], fourth);

  Base* decimal_one = new Op(1);
  Base* decimal_two = new Op(2);
  Base* expression = new Pow(decimal_one, decimal_two);

  EXPECT_EQ(test->parse(input, 4)->evaluate(), expression->evaluate()); 
}

//2 ^ 2 ^ 2 ^ 2 ^ 2
TEST(ClassPowerTest, PowMultipleEvaluateNonZero) {
  Factory* test = new Factory();
  char** input = new char*[8];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="2"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[3] ="**"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="2"; 
  input[3] = new char[strlen(fourth) + 1];
  strcpy(input[3], fourth);

  char fifth[3] ="**"; 
  input[4] = new char[strlen(fifth) + 1];
  strcpy(input[4], fifth);

  char sixth[2] ="2"; 
  input[5] = new char[strlen(sixth) + 1];
  strcpy(input[5], sixth);

  char seventh[3] ="**"; 
  input[6] = new char[strlen(seventh) + 1];
  strcpy(input[6], seventh);

  char eigth[2] ="2"; 
  input[7] = new char[strlen(eigth) + 1];
  strcpy(input[7], eigth);

  Base* decimal_one = new Op(2);
  Base* decimal_two = new Op(2);
  Base* expression_one = new Pow(decimal_one, decimal_two);
  //1 + 1
  Base* decimal_three = new Op(2);
  Base* expression_two = new Pow(expression_one, decimal_three);
  //1 + 1 + 1

  Base* decimal_four = new Op(2);
  Base* expression_three = new Pow(expression_two, decimal_four);
  //1 + 1 + 1 + 1
  EXPECT_EQ(test->parse(input, 8)->evaluate(), expression_three->evaluate()); 
}

// 1 +
TEST(ClassPowerTest, PowInvalidEndWithOperator) {
  Factory* test = new Factory();
  char** input = new char*[3];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[3] ="**"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  EXPECT_TRUE(test->parse(input, 3) == nullptr);
}

TEST(ClassPowerTest, PowInvalidStartWithOperator) {
  Factory* test = new Factory();
  char** input = new char*[3];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[3] ="**"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="1"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  EXPECT_TRUE(test->parse(input, 3) == nullptr);
}

// // 1a +
TEST(ClassPowerTest, PowMixedOperand) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[3] ="1a"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[3] ="**"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="1"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  EXPECT_TRUE(test->parse(input, 4) == nullptr);
}

// a
TEST(ClassPowerTest, PowInvalidOperand) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="a"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[3] ="**"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="1"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  EXPECT_TRUE(test->parse(input, 4) == nullptr);
}



