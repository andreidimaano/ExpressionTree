#include "../header/mult.hpp"

Mult::Mult(Base* left, Base* right) : Base() {
  this->left = left;
  this->right = right;
}

double Mult::evaluate() {
  return this->left->evaluate() * this->right->evaluate();
}

std::string Mult::stringify() {
  return (this->left->stringify() + " * " + this->right->stringify());
}
