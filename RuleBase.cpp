//---------------------------------------------
// RuleBase.cpp
//---------------------------------------------

#include "RuleBase.h"

RuleBase::RuleBase() {

	numRules = 0;

}

void RuleBase::createRule(string name, string param, string logic, string categories, string dollarParams) {
	
	if (checkRule(name) == -1) {
		
		vector <Rule*> newRule;
		rules[name] = newRule;

	}

	Rule* A = new Rule(param, logic);

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

auto RuleBase::getRule(string name) {

	try {

		if (checkRule(name) == 1) {
			return rules[name];
		}
		else {
			throw;
			return rules[name];
		}
	}
	catch (...) {

		cout << "getRule Error: rule" << name << " not found." << endl;

	}

}

map < string, vector <Rule*> > RuleBase::getAllRules() {

	return rules;

}

int RuleBase::checkRule(string name) {

	auto it = rules.find(name);

	if (it != rules.end()) return 1;
	else return -1;

}



RuleBase::~RuleBase() {

}