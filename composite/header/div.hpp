#ifndef DIV_H
#define DIV_H

#include "../../base.hpp"

class Div : public Base
{
	public:
		Div(Base* left, Base* right);
		double evaluate() override;
		std::string stringify() override;
	private:
		Base* left;
		Base* right;
};
#endif
