#include "../header/pow.hpp"
#include <math.h> 

Pow::Pow(Base* left, Base* right) : Base() {
  this->left = left;
  this->right = right;
}

double Pow::evaluate() {
  return pow(this->left->evaluate(), this->right->evaluate());
}

std::string Pow::stringify() {
  return (this->left->stringify() + " ** " + this->right->stringify());
}
