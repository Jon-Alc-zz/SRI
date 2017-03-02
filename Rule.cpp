//----------------------------------------
// Rule.cpp
//----------------------------------------

#include "Rule.h"

// Constructor
Rule::Rule(string newArg, string newLogic, string paramName, string paramArg) {

	int unsigned strPos = 0;
	int unsigned strPos2 = 0;
	int unsigned strPos3 = 0;
	int unsigned index = 0;
	string strTemp = "";
	string newpArg = "";

	// removes all whitespace for new Arg
	while (newArg.find(" ") != string::npos) {
		strPos = newArg.find(" ");
		newArg.erase(newArg.begin() + strPos);
	}

	do {

		strPos = newArg.find(",");                     // searches for index of ','

		if (strPos != 0) { 

			strTemp.assign(newArg, 0, strPos);
			rule_param.push_back(strTemp);            // add to end of 'rule_param' vector

		}

		newArg.erase(0, strPos + 1);                  // erases the added string

	} while (strPos != string::npos);

	// reset position and Temp
	strPos = 0;
	strTemp = "";

	// removes all whitespace in paramName
	while (paramName.find(" ") != string::npos) {
		strPos = paramName.find(" ");
		paramName.erase(paramName.begin() + strPos);
	}

	// removes all whitespace in paramArg
	while (paramArg.find(" ") != string::npos) {
		strPos2 = paramArg.find(" ");
		paramArg.erase(paramArg.begin() + strPos2);
	}

	do {

		strPos = paramName.find(",");                // searches for index of ','

		if (strPos != 0) { 

			strTemp.assign(paramName, 0, strPos);
			param_name.push_back(strTemp);           // add to end of 'param_name' vector
			
		}

		paramName.erase(0, strPos + 1);              // erases the added string

	} while (strPos != string::npos);

	do {

		strPos = paramArg.find(")");                 // searches for index of ')'
		
		if (strPos != string::npos) {

			newpArg.assign(paramArg, 0, strPos + 1); // one set of parameters are given to newpArg
			paramArg.erase(0, strPos + 1);           // the given part is deleted
			strPos = newpArg.find("(");              // searches for index of '('
			newpArg.erase(0, strPos + 1);            // everything up to and on '(' is deleted


			do {
				
				strPos = newpArg.find(')');          // new search position looking for '('
				strPos2 = newpArg.find(",");         // new search position looking for ','
				strPos3 = newpArg.find("$");         // new search position looking for '$'
				

				if (strPos2 >= 0) {                  // runs through here if there is a ','
					strTemp.assign(newpArg, strPos3, strPos2);
					params[index].push_back(strTemp);
					newpArg.erase(0, strPos2 + 1);
				}
				else if (strPos3 >= 0) {             // runs through here is there is '$' and there are no ','
					strTemp.assign(newpArg, strPos3, strPos);
					params[index].push_back(strTemp);
					newpArg.erase(0, strPos + 1);
				}
				else {                               // if there are no '$' or ',' store then it breaks
					break;
				}
				
			} while (true);

			index++;

		}

	} while (param_name.size() > index);

	logic = newLogic;

}

// Methods

// It gets the parameters of the rule

map <int, vector <string> > Rule::getParam() {
	return params;
}

vector <string> Rule::getRuleParams() {
	return rule_param;
}

vector <string> Rule::getParamName() {
	return param_name;
}

// It gets the logic of the rule
string Rule::getLogic() {
	return logic;
}

// Debug tool
void Rule::printRule() {
	cout << "Rule Arguments: ";
	for (unsigned int i = 0; i < rule_param.size(); i++) cout << rule_param[i] << " ";
	
	cout << "\nLogic: " << logic << endl;
	
	cout << "Rule Params:\n";

	for (unsigned int i = 0; i < param_name.size(); i++) {
		cout << param_name[i] << ": ";

		for (unsigned int ii = 0; ii < params[i].size(); ii++) cout << params[i][ii] << " ";

		cout << "\n";
	}
	
}

// Destructor
Rule::~Rule() {

}
