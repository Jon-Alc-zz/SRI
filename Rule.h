//-----------------------------------
// Rule.h
//-----------------------------------

#ifndef __RULE_H
#define __RULE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class Rule {

private:

	string logic;      // Either "and" or "or"
	string rule_param; // The paramaters of the rule
	vector <string> names_param;

public:

	// Constructor
	Rule(string newParam, string newLogic);

	// Methods
	string getParam();
	string getLogic();

	// Destructor
	~Rule();
};

#endif

