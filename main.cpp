#include <iostream>
#include "composite/header/add.hpp"
#include "composite/header/sub.hpp"
#include "composite/header/div.hpp"
#include "composite/header/op.hpp"
#include "composite/header/pow.hpp"
#include "composite/header/mult.hpp"
#include "Factory.hpp"
#include "base.hpp"
#include <string>

using namespace std;


int main(int argc, char**argv) {
    Factory* expressionTree = new Factory();
    
    for(unsigned i = 0; i < argc; i++) {
      cout << argv[i] << endl;
    }

    Base* result = expressionTree->parse(argv, argc);

    if(!result) {
      cout << "invalid expression Tree" << endl;
    } else {
      cout << result->stringify() << " = " << result->evaluate() << endl;
    }

    return 0;
}
