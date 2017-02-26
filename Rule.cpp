//----------------------------------------
// Rule.cpp
//----------------------------------------

#include "Rule.h"

Rule::Rule(string newParam, string newLogic) {

	param = newParam;
	logic = newLogic;

}

string Rule::getParam() {
	return param;
}

string Rule::getLogic() {
	return logic;
}



Rule::~Rule() {

}
