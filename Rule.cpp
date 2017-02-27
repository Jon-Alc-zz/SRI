//----------------------------------------
// Rule.cpp
//----------------------------------------

#include "Rule.h"

// Constructor
Rule::Rule(string newParam, string newLogic) {

	rule_param = newParam;
	logic = newLogic;

}

// Methods

// It gets the parameters of the rule
string Rule::getParam() {
	return rule_param;
}

// It gets the logic of the rule
string Rule::getLogic() {
	return logic;
}

// Destructor
Rule::~Rule() {

}
