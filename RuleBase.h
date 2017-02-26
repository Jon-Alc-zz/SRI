//-----------------------------------------------
// RuleBase.h
//-----------------------------------------------

#ifndef __RULEBASE_H
#define __RULEBASE_H

#include "Rule.h"
#include <string>
#include <vector>

using namespace std;

class RuleBase {

private:

	vector <Rule* > rules;

public:

	RuleBase();

	void createRule(string name, string spec);
	void deleteRule(string name);
	void checkRule(string name);

	~RuleBase();

};

#endif 

