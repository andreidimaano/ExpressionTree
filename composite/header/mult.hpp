#ifndef MULT_H
#define MULT_H

#include "../../base.hpp"

class Mult : public Base
{
	public:
		Mult(Base* left, Base* right);
		double evaluate() override;
		std::string stringify() override;
	private:
		Base* left;
		Base* right;
};
#endif
