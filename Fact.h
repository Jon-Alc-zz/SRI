//-----------------------------------
//Fact.h
//-----------------------------------

#ifndef __FACT_H
#define __FACT_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Fact {

	private:

		vector <string> things;
		string name;
		int length;

	public:

		Fact(string factName, string thingString);
		~Fact();

	protected:

};


#endif