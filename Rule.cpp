//----------------------------------------
// Rule.cpp
//----------------------------------------

#include "Rule.h"

Rule::Rule(string newName, string newSpecs) {
	name = newName;
	specs = newSpecs;
}

string Rule::getSpecs() {
	return specs;
}

Rule::~Rule() {

}
