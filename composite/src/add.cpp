#include "../header/add.hpp"

Add::Add(Base* left, Base* right) : Base() {
	this->left = left;
	this->right = right;
}

double Add::evaluate() {
	return this->left->evaluate() + this->right->evaluate();
}

std::string Add::stringify() {
	return (this->left->stringify() + " + " + this->right->stringify());
}
