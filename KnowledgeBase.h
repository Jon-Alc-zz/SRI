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
#include "Fact.h"

using namespace std;

class KnowledgeBase{

private:

	vector <Fact *> facts;

public:

	KnowledgeBase();
	Fact* getFacts(string fact);
	void CreateFact(string name, vector <string&> facts);
	void DeleteFact(string fact);
	~KnowledgeBase();

protected:

};

#endif