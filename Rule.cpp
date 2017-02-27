//----------------------------------------
// Rule.cpp
//----------------------------------------

#include "Rule.h"

// Constructor
Rule::Rule(string newArg, string newLogic, string paramName, string paramArg) {

	int strPos = 0;
	int strPos2 = 1;
	int index = 0;
	string strTemp = "";
	vector <string> Temp;

	// removes all whitespace for new Arg
	while (newArg.find(" ") != string::npos) {
		strPos = newArg.find(" ");
		newArg.erase(newArg.begin() + strPos);
	}

	do {

		strPos = newArg.find(","); // searches for index of ','

		if (strPos != 0) { // catches "thing1,, thing2"

			strTemp.assign(newArg, 0, strPos);
			rule_param.push_back(strTemp); // add to end of 'rule_param' vector

		}

		newArg.erase(0, strPos + 1); // erases the added string

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

		strPos = paramName.find(","); // searches for index of ','

		if (strPos != 0) { // catches "thing1,, thing2"

			strTemp.assign(paramName, 0, strPos);
			Temp.push_back(strTemp); // add to end of 'temp' vector
			
		}

		paramName.erase(0, strPos + 1); // erases the added string

	} while (strPos != string::npos);



	do {

		strPos = paramArg.find("("); // searches for index of '('

		paramArg.erase(0, strPos + 1);

		if (strPos != 0) {

			do {
				
				strPos2 = paramArg.find(","); // new search position looking for ','

				if (strPos2 != 0) {

					strTemp.assign(paramArg, 0, strPos2); // assigns the argument to the strTemp
					params[Temp[index]].push_back(strTemp); // in maps it to its appropiate vector

				}

				paramArg.erase(0, strPos2 + 1); // erases the added string

			} while (strPos2 < paramArg.find(")"));

			strPos2 = paramArg.find(")"); // deletes the rest of the 

			paramArg.erase(0, strPos2 + 1);

			index++;

		}

	} while (strPos != string::npos);

	// rule_param = newParam; not sure what's going on here
	logic = newLogic;

}

// Methods

// It gets the parameters of the rule

map <string, vector <string> > Rule::getParam() {
	return params;
}

vector <string> Rule::getRuleParams() {
	return rule_param;
}

// It gets the logic of the rule
string Rule::getLogic() {
	return logic;
}

// Destructor
Rule::~Rule() {

}
