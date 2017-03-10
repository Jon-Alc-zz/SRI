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

	// Variables
	map < string, vector <Rule*> > rules;         // Stores all the rules in a map of vectors <Rules*>
	vector <string> names;                        // Stores the names of the Rules

public:

	// Constructor
	RuleBase();

	// Methods
	void createRule(string name, string param, string logic, string paramName, string paramArg);
	void deleteRule(string name);
	vector<Rule*> getRule(string name);
	map < string, vector <Rule*> > getAllRules();
	int checkRule(string name);

	// Deconstructor
	~RuleBase();

};

#endif 

