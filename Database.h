//-----------------------------------
//DataBase.h
//-----------------------------------

#ifndef __DATABASE_H
#define __DATABASE_H

#include "KnowledgeBase.h"
#include <fstream>
#include <sstream>

class Database{

private:

	KnowledgeBase* KB;

public:

	Database();
	void Parse(string input);
	void Load(string fileName);
	void Dump(string fileName);
	void MakeFact(string params);
	void MakeRule(string params);
	void Inference(string params);

protected:

};


#endif