//-----------------------------------
//Fact.cpp
//-----------------------------------

#include "Fact.h"

Fact::Fact(string thingString) {

	int thingLength = 0;
	int strPos = 0;
	string strTemp = "";

	while (true) {

		// removes all whitespace
		while (strPos = thingString.find(" ") != string::npos)
			strTemp.erase(strTemp.begin() + strPos);

		strPos = thingString.find(","); // searches for index of ','

		if (strPos != 1) { // catches "thing1,, thing2"

			if (strPos == string::npos) // if there's 1 argument
				strTemp.assign(thingString, 0, strTemp.length());
			else
				strTemp.assign(thingString, 0, strPos);

			things.push_back(strTemp); // add to end of 'things' vector

		}

		// if there's no commas, end the loop
		if (strPos == string::npos)
			break;

	}

	length = thingLength;
	if (!thingString.empty()) { thingString.clear(); }

}

Fact::~Fact() {

}