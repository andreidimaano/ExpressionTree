#include "gtest/gtest.h"

//#include "factory_subtraction_test.hpp"
#include "factory_addition_test.hpp"
#include "factory_division_test.hpp"
#include "factory_power_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
