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

	string specs;
	string name;

public:

	Rule(string newName, string newSpecs);

	string getSpecs();

	~Rule();
};

#endif

