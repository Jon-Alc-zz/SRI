//---------------------------------------------
// RuleBase.cpp
//---------------------------------------------

#include "RuleBase.h"

RuleBase::RuleBase() {

}


void RuleBase::createRule(string name, string param, string logic, string paramName, string paramArg) {
	
	if (checkRule(name) == -1) {
		
		vector <Rule*> newRule;
		rules[name] = newRule;
		names.push_back(name);

	}

	Rule* A = new Rule(param, logic, paramName, paramArg);

	rules[name].push_back(A);

}

void RuleBase::deleteRule(string name) {

	if (checkRule(name) == -1) {
		
	}
	else {

		vector <Rule*> tempRules = rules[name];

		for (unsigned int i = 0; i < tempRules.size(); i++) {
			delete(tempRules[i]);
		}
		
		rules[name].clear();
	}

}

vector<Rule*> RuleBase::getRule(string name) {
	vector<Rule*> emptyRules;

	if (checkRule(name) == 1) {
		return rules[name];
	}

	return emptyRules;
}

map < string, vector <Rule*> > RuleBase::getAllRules() {

	return rules;

}

int RuleBase::checkRule(string name) {

	for (unsigned int i = 0; i < names.size(); i++) {
		if (names[i] == name) return 1;
	}

	return -1;
}



RuleBase::~RuleBase() {
	//cout << "Rulebase is gone." << endl;

	map < string, vector <Rule*> > tempMap = getAllRules();
	vector <Rule*> tempRules;

	for (map < string, vector <Rule*> >::iterator it = tempMap.begin(); it != tempMap.end(); ++it) {
		
		tempRules = tempMap[it->first];

		for (unsigned int i = 0; i < tempRules.size(); i++) {
			delete(tempRules[i]);
		}

	}

}