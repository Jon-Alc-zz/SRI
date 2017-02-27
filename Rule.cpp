//----------------------------------------
// Rule.cpp
//----------------------------------------

#include "Rule.h"

// Constructor
Rule::Rule(string newParam, string newLogic) {

	param = newParam;
	logic = newLogic;

}

// Methods

// It gets the parameters of the rule
string Rule::getParam() {
	return param;
}

// It gets the logic of the rule
string Rule::getLogic() {
	return logic;
}

// Destructor
Rule::~Rule() {

}
