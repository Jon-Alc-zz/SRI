//-----------------------------------
//KnowledgeBase.h
//-----------------------------------

#ifndef __KNOWLEDGEBASE_H
#define __KNOWLEDGEBASE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
//#include Fact.h

class KnowledgeBase{

private:

	vector <Facts *> facts;

public:

	KnowledgeBase();
	void Facts * getFacts(string fact);
	void CreateFact(string name, vector <string>& facts);
	void DeleteFact(string fact);
	~KnowledgeBase();

protected:

}

#endif