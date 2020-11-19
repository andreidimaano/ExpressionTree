#include "../header/div.hpp"

Div::Div(Base* left, Base* right) : Base() {
	this->left = left;
	this->right = right;
}

double Div::evaluate() {
	if(this->right->evaluate() == 0{
		return -1;
	}

	return this->left->evaluate() / this->right->evaluate();
}

std::string Div::stringify() {
	return (this->left->stringify() + " / " + this->right->stringify());
} 
