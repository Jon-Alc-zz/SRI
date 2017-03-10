//-----------------------------------
//Fact.cpp
//-----------------------------------

#include "Fact.h"

Fact::Fact(string thingString) {

	int thingLength = 0;
	int strPos = 0;
	string strTemp = "";

	// removes all whitespace
	while (thingString.find(" ") != string::npos) {
		strPos = thingString.find(" ");
		thingString.erase(thingString.begin() + strPos);
	}

	 do {

		strPos = thingString.find(","); // searches for index of ','

		if (strPos != 0) { // catches "thing1,, thing2"

			strTemp.assign(thingString, 0, strPos);
			things.push_back(strTemp); // add to end of 'things' vector
			
		}

		thingString.erase(0, strPos + 1); // erases the added string

	 } while (strPos != string::npos);

	length = thingLength;

}

vector <string> Fact::GetThings() {
	return things;
}

Fact::~Fact() {
	//cout << "Fact is gone" << endl;
}