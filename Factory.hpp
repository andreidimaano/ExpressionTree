#ifndef FACTORY_H
#define FACTORY_H
#include "base.hpp"
#include "composite/header/add.hpp"
#include "composite/header/op.hpp"
#include "composite/header/sub.hpp"
#include "composite/header/div.hpp"
#include "composite/header/pow.hpp"
#include <cstring>
#include <iostream>
#include <stdlib.h>


class Factory
{
    private:
        Base* createExpression(Base* prevOperand, char currentOperator, Base* currentOperand){
            //switch case for Operator
            switch(currentOperator) {
                case '+': {
                    return new Add(prevOperand, currentOperand);
                    break;
		        }
                //implement other cases
                case '-' : {
                    return new Sub(prevOperand, currentOperand);
                    break;
			    }
                case '/': {
                    if(currentOperand->evaluate() == 0) std::cout << "Cannot divide by zero" << std:: endl;
                    return (currentOperand->evaluate() == 0) ? nullptr : new Div(prevOperand, currentOperand);
                    break;
                }
                case '^': {
                    return new Pow(prevOperand, currentOperand);
                    break;
                }
                default: {
                    return nullptr;
                }
            }
        }

        bool validateOperator(char* input){
            int length = strlen(input);
            if(length == 1){
                //check for valid operators
                    //finish the rest of the operators
                    //i.e add to the condition statement
                    // || input[0] != '*'
                if(input[0] != '+' && input[0] != '-' && input[0] != '/'){
                    return false;
                }
            }


            if(length == 2 && input[0] != '*' && input[1] != '*') return false;

            return true;
        }

    public:
        Factory() {}
        
        Base* parse(char** input, int length){
            Base* prevOperand = nullptr;
            Base* currentOperand = nullptr;
            char currentOperator;
            bool endsWithOperator = false;
            for(unsigned i = 1; i < length; i++){
                //Check for Number
                char * endptr;
                int charToInt = (int) strtol(input[i], &endptr, 10);
                if(endptr != input[i]){
                    if((*endptr) && (*endptr <= '0' || *endptr >= '9')){
                        //std::cout << "i: " << i << std::endl;
                        //if input is "1a" then the expression is invalid
                        return nullptr;
                    }
                    if(!prevOperand){
                        //prevOperand == nullptr
                        //case for "+ 5"
                        if(currentOperator) {
                            //std::cout << "i: " << i << std::endl;
                            return nullptr;
                        }
                        prevOperand = new Op(charToInt);
                        endsWithOperator = false;
                    } else {
                        //reassign prevOperand
                        currentOperand = new Op(charToInt);
                        prevOperand = createExpression(prevOperand, currentOperator, currentOperand);
                        //std::cout << "evaluate: " << prevOperand->evaluate();
                        //deallocate space
                        //delete currentOperand;
                
                        //reset currentOperator
                        currentOperator = '\0';
                        endsWithOperator = false;
                    }    
                } else if(!validateOperator(input[i])) {
                    return nullptr;
                } else {
                    //std::cout << "i: " << i << std::endl;
			        currentOperator = (strlen(input[i]) == 2) ? '^' : input[i][0];
                    endsWithOperator = true;
            	}
	        }
        //return most recent expression or nullptr
        //checks case for "1 +"
	    return (endsWithOperator) ? nullptr : prevOperand;
        };
};

#endif