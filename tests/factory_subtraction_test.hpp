#ifndef __sub_factory__
#define __sub_factory__

#include "gtest/gtest.h"
#include "../Factory.hpp"
#include "../composite/header/op.hpp"
#include "../composite/header/add.hpp"
#include "../composite/header/sub.hpp"
#include <cstring>



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

#endif
