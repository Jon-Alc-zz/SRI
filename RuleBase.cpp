//---------------------------------------------
// RuleBase.cpp
//---------------------------------------------

#include "RuleBase.h"

RuleBase::RuleBase() {

	numRules = 0;

}


void RuleBase::createRule(string name, string param, string logic, string paramName, string paramArg) {
	
	if (checkRule(name) == -1) {
		
		vector <Rule*> newRule;
		rules[name] = newRule;
		names.push_back(name);

	}

	Rule* A = new Rule(param, logic, paramName, paramArg);

	rules[name].push_back(A);

	numRules++;
}

void RuleBase::deleteRule(string name) {

	if (checkRule(name) == -1) {
		
	}
	else {

		rules.erase(name);
		numRules--;
	}

}

vector<Rule*> RuleBase::getRule(string name) {

	if (checkRule(name) == 1) {
		return rules[name];
	}

}

map < string, vector <Rule*> > RuleBase::getAllRules() {

	return rules;

}

int RuleBase::checkRule(string name) {

	for (int i = 0; i < names.size(); i++) {
		if (names[i] == name) return 1;
	}

	return -1;
}



RuleBase::~RuleBase() {

}