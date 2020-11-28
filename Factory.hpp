#include "base.hpp"
#include "composite/header/add.hpp"
#include "composite/header/op.hpp"
#include <cstring>
#include <stdlib.h>

class Factory
{
    private:
        void createExpression(Base* prevOperand, char currentOperator, Base* currentOperand){
            //switch case for Operator
            switch(currentOperator) {
                case '+':
                    Base* temp = prevOperand;
                    prevOperand = new Add(prevOperand, currentOperand);
                    delete temp;
                //implement other cases
                default:
                    Base* temp = prevOperand;
                    prevOperand = nullptr;
                    delete temp;
            }
        }

        bool validateOperator(char* input){
            int length = strlen(input);
            
            if(length == 1){
                //check for valid operators
                    //finish the rest of the operators
                    //i.e add to the condition statement
                    // || input[0] != '*'
                if(input[0] != '+'){
                    return false;
                }
            }

            if(length == 2 && input[0] != '*' && input[1] != '*') return false;

            return true;
        }

    public:
        Factory() {};
        
        Base* parse(char** input, int length){
            Base* prevOperand;
            char currentOperator;
            for(unsigned i = 1; i < length; i++){
                //Check for Number
                char * endptr;
                int charToInt = (int) strtol(input[i], &endptr, 10);
                if(endptr != input[i]){
                    if((*endptr) && (*endptr <= '0' || *endptr >= '9')){
                        //if input is "1a" then the expression is invalid
                        return nullptr;
                    }
                    if(!prevOperand){
                        //prevOperand == nullptr
                        prevOperand = new Op(charToInt);
                    } else {
                        //reassign prevOperand
                        Base* currentOperand = new Op(charToInt);
                        createExpression(prevOperand, currentOperator, currentOperand);
                        
                        //deallocate space
                        delete currentOperand;
                
                        //reset currentOperator
                        currentOperator = '\0';
                    }    
                }            
                //Check for Operator
                if(!validateOperator(input[i])) return false;
                currentOperator = (strlen(input[i]) == 2) ? '^' : input[i][0];
            }

        //return most recent expression or nullptr
	    return prevOperand;
        };
};

// 3 + 2 + 3
// 4 \* 3
// 4 \*\* 3
// invalid inputs:
// operator and operator
    // 4 + + 3
    // 4 +/ 3
    // 4
