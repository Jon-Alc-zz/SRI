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

	map<string, vector<Fact*> > KBmp;
	map<string, vector<Fact*> >::iterator it;

public:

	KnowledgeBase();
	int CheckFact(string fact);
	vector<Fact*> getFacts(string fact);
	map<string, vector<Fact*> > GetAllFacts();
	void CreateFact(string name, string things);
	void DeleteFact(string fact);
	~KnowledgeBase();

protected:

};

#endif