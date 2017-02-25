//-----------------------------------
//KnowledgeBase.h
//-----------------------------------

#ifndef __KNOWLEDGEBASE_H
#define __KNOWLEDGEBASE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Fact.h"

class KnowledgeBase{

private:

	vector <Fact *> facts;

public:

	KnowledgeBase();
	void Fact * getFacts(string fact);
	void CreateFact(String name, vector <string>& facts);
	void DeleteFact(String fact);
	~KnowledgeBase();

protected:

};

#endif