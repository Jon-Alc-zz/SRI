//-----------------------------------
// Rule.h
//-----------------------------------

#ifndef __RULE_H
#define __RULE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Rule {

private:

	string specs;
	string name;

public:

	Rule(string name, string specs);

	string getSpecs(string name);

	~Rule();
};

#endif

