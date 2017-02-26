//---------------------------------------------
// RuleBase.cpp
//---------------------------------------------

#include "RuleBase.h"

RuleBase::RuleBase() {

}

void RuleBase::createRule(string name, string param, string logic) {

	numRules++;
}

void RuleBase::deleteRule(string name) {
	int index = checkRule(name);

	if (index == -1) {
		cout << "deleteRule Error:" << name << "not found" << endl;
	}
	else {
		index--;

	}

}

int RuleBase::checkRule(string name) {
	for (int i = 0; i < numRules; i++) {

		if (rules[i].getName() == name) return i;

	}

	return -1;
}



RuleBase::~RuleBase() {

}