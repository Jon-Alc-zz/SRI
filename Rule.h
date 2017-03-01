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

	// Variables
	string logic;                                      // Either "and" or "or"
	vector <string> rule_param;                        // The paramaters of the rule
	vector <string> param_name;                        // The name of the parameters of the rule
	map <int, vector <string> > params;             // contains all of the necessary params within the rule
	map <int, vector <string> >::iterator it;

	// Debug Method
	void printRule();

public:

	// Constructor
	Rule(string newArg, string newLogic, string paramName, string paramArg);

	// Methods
	map <int, vector <string> > getParam();
	vector <string> getRuleParams();
	vector <string> getParamName();
	string getLogic();

	// Destructor
	~Rule();
};

#endif

