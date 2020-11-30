#ifndef SUB_H
#define SUB_H

#include "../../base.hpp"

class Sub : public Base
{
	public:
		Sub();
		Sub(Base* left, Base* right);
		double evaluate() override;
		std::string stringify() override;
	private:
		Base* left; 
		Base* right;
};
#endif
