#include "../header/op.hpp"

Op::Op(double val) : Base() {
	this->value = val;
}

double Op::evaluate() {
	return this->value;
}

std::string Op::stringify() {
	return std::to_string(this->value);
}
