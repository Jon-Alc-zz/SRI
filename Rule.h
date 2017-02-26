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

	string logic;
	string param;

public:

	Rule(string newParam, string newLogic);

	string getParam();
	string getLogic();

	~Rule();
};

#endif

