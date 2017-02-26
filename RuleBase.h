//-----------------------------------------------
// RuleBase.h
//-----------------------------------------------

#ifndef __RULEBASE_H
#define __RULEBASE_H

#include "Rule.h"
#include <string>
#include <map>

using namespace std;

class RuleBase {

private:

	map <string,Rule> rules;
	int numRules;

public:

	RuleBase();

	void createRule(string name, string param, string logic);
	void deleteRule(string name);
	int checkRule(string name);

	~RuleBase();

};

#endif 

