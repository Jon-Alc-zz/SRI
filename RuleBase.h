//-----------------------------------------------
// RuleBase.h
//-----------------------------------------------

#ifndef __RULEBASE_H
#define __RULEBASE_H

#include "Rule.h"

class RuleBase {

private:

	vector <Rule* > rules;

public:

	RuleBase();

	void createRule(string spec);
	void deleteRule(string name);
	void checkRule(string name);

	~RuleBase();

};

#endif 

