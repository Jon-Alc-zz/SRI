//-----------------------------------
//KnowledgeBase.h
//-----------------------------------

#ifndef __KNOWLEDGEBASE_H
#define __KNOWLEDGEBASE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include "Fact.h"

using namespace std;

class KnowledgeBase{

private:

<<<<<<< HEAD
=======
	vector <Fact*> facts;
>>>>>>> bec09dff11b2650b1c5da63da253d60cd3c33bff
	map<string, vector<Fact*> > KBmp;
	map<string, vector<Fact*> >::iterator it;

public:

	KnowledgeBase();
	int CheckFact(string fact);
	auto getFacts(string fact);
	map<string, vector<Fact*> > GetAllFacts();
	void CreateFact(string name, string things);
	void DeleteFact(string fact);
	~KnowledgeBase();

protected:

};

#endif