#include "base.hpp"

class Factory
{
    public:
        Factory() {};
        Base* parse(char** input, int length){
            
            for(unsigned i = 1; i < length; i++){
                //Prev Operand
                //Char prevOperator

                //Check for Number
                    //If Prev Operand == nullptr,
                        //Set PrevOperand
                    //else Prev Operand exists
                        //Check PrevOperator
                        //Create new Base*
                //Check for Space
                //Check for Operator
                    //special case = power
                        // \*\*
                    //*
                    ///
                    //+
                    //-
            }
        };
};