//-----------------------------------
//Fact.h
//-----------------------------------

#ifndef __FACT_H
#define __FACT_H

#include <iostream>
#include <cstdio>
#include <cstdlib>

class Fact{

private:

	vector <JonsMeat *> jonsmeat;
	string name;
	int length;

public:

	Fact();
	void Fact(string name, vector <string>& jonsmeat);
	~Fact();

protected:

}


#endif