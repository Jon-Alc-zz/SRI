//-----------------------------------
// Rule.h
//-----------------------------------

#ifndef __RULE_H
#define __RULE_H

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

class Rule {

private:

	string logic;                               // Either "and" or "or"
	vector <string> rule_param;                 // The paramaters of the rule
	map <string, vector <string> > params;      // contains all of the necessary params within the rule
	map <string, vector <string> >::iterator it;

public:

	// Constructor
	Rule(string newArg, string newLogic, string paramName, string paramArg);

	// Methods
	map <string, vector <string> > getParam();
	vector <string> getRuleParams();
	string getLogic();

	// Debug Method
	void printRule();

	// Destructor
	~Rule();
};

#endif

