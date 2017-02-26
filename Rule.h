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

	vector <string> logic;
	vector <string> param;
	int numSpecs;

public:

	Rule(string newParam, string newLogic);

	string getSpecs();
	void addSpec();

	~Rule();
};

#endif

