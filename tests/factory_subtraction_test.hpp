#ifndef __sub_factory__
#define __sub_factory__

#include "gtest/gtest.h"
#include "../Factory.hpp"
#include "../composite/header/op.hpp"
#include "../composite/header/add.hpp"
#include "../composite/header/sub.hpp"
#include <cstring>


//
TEST(ClassSubtractionTest, SubEvaluateZero) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="-"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="0"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  Base* decimal_one = new Op(1);
  Base* decimal_zero = new Op(0);

  Base* subtractionComposite = new Sub(decimal_one, decimal_zero);

  EXPECT_EQ(test->parse(input, 4)->evaluate(), subtractionComposite->evaluate());
}



TEST(ClassSubtractionTest, SubEvaluateZeroString) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="-"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="0"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  Base* decimal_one = new Op(1);
  Base* decimal_zero = new Op(0);

  Base* subtractionComposite = new Sub(decimal_one, decimal_zero);

  EXPECT_EQ(test->parse(input, 4)->stringify(), subtractionComposite->stringify());
}



TEST(ClassSubtractionTest, SubEvaluateNonZero) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="-"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="2"; 
  input[3] = new char[strlen(fourth) + 1];
  strcpy(input[3], fourth);

  Base* decimal_one = new Op(1);
  Base* decimal_two = new Op(2);
  Base* expression = new Sub(decimal_one, decimal_two);

  EXPECT_EQ(test->parse(input, 4)->evaluate(), expression->evaluate()); 
}



TEST(ClassSubtractionTest, SubMultipleEvaluateNonZero) {
  Factory* test = new Factory();
  char** input = new char*[8];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="-"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="1"; 
  input[3] = new char[strlen(fourth) + 1];
  strcpy(input[3], fourth);

  char fifth[2] ="-"; 
  input[4] = new char[strlen(fifth) + 1];
  strcpy(input[4], fifth);

  char sixth[2] ="1"; 
  input[5] = new char[strlen(sixth) + 1];
  strcpy(input[5], sixth);

  char seventh[2] ="-"; 
  input[6] = new char[strlen(seventh) + 1];
  strcpy(input[6], seventh);

  char eigth[2] ="1"; 
  input[7] = new char[strlen(eigth) + 1];
  strcpy(input[7], eigth);

  Base* decimal_one = new Op(1);
  Base* decimal_two = new Op(1);
  Base* expression_one = new Sub(decimal_one, decimal_two);
  //1 + 1
  Base* decimal_three = new Op(1);
  Base* expression_two = new Sub(expression_one, decimal_three);
  //1 + 1 + 1
  //
  Base* decimal_four = new Op(1);
  Base* expression_three = new Sub(expression_two, decimal_four);
  //1 + 1 + 1 + 1
  EXPECT_EQ(test->parse(input, 8)->evaluate(), expression_three->evaluate()); 
}

TEST(ClassSubtractionTest, SubInvalidEndWithOperator) {
  Factory* test = new Factory();
  char** input = new char*[3];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="-"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  EXPECT_TRUE(test->parse(input, 3) == nullptr);
} 


TEST(ClassSubtractionTest, SubInvalidStartWithOperator) {
  Factory* test = new Factory();
  char** input = new char*[3];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="-"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="1"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  EXPECT_TRUE(test->parse(input, 3) == nullptr);
}



TEST(ClassSubtractionTest, SubMixedOperand) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[3] ="1a"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="-"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="1"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  EXPECT_TRUE(test->parse(input, 4) == nullptr);
}


TEST(ClassSubtractionTest, SubInvalidOperand) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="a"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="-"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="1"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  EXPECT_TRUE(test->parse(input, 4) == nullptr);
}
#endif
