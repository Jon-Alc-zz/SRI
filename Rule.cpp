//----------------------------------------
// Rule.cpp
//----------------------------------------

#include "Rule.h"

Rule::Rule(string newParam, string newLogic) {

	param.push_back(newParam);
	logic.push_back(newLogic);
	numSpecs = 1;

}

vector Rule::getParam() {

}

vector Rule::getLogic() {

}



Rule::~Rule() {

}
