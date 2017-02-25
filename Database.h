//-----------------------------------
//Fact.h
//-----------------------------------

#ifndef __DATABASE_H
#define __DATABASE_H

#include "KnowledgeBase.h"

class Database{

private:

	KnowledgeBase KB;

public:

	void Parse(string input);
	void Load(string fileName);
	void Dump(string fileName);
	void MakeFact(string params);
	void MakeRule(string params);
	void Inference(string params);

protected:

};


#endif