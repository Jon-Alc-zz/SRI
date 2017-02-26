//---------------------------------------------
// RuleBase.cpp
//---------------------------------------------

#include "RuleBase.h"

RuleBase::RuleBase() {

}

void RuleBase::createRule(string name, string param, string logic) {
	
	if (checkRule(name) == -1) {
		
		vector <Rule*> newRule;
		rules[name] = newRule;

	}

	Rule* A = new Rule(param, logic);

	rules[name].push_back(A);

	numRules++;
}

void RuleBase::deleteRule(string name) {

	if (checkRule(name); == -1) {
		
	}
	else {

		rules.erase(name);
	}

}

int RuleBase::checkRule(string name) {
	auto it = rules.find(name);

	if (it != rules.end()) {
		return 1;
	}
	else {
		
		return -1;
	}

}



RuleBase::~RuleBase() {

}