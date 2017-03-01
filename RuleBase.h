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

	map < string, vector <Rule*> > rules;
	int numRules;

public:

	RuleBase();

	void createRule(string name, string param, string logic, string paramName, string paramArg);
	void deleteRule(string name);
	vector<Rule*> getRule(string name);
	map < string, vector <Rule*> > getAllRules();
	int checkRule(string name);

	~RuleBase();

};

#endif 

