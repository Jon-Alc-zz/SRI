//-----------------------------------
//DataBase.h
//-----------------------------------

#ifndef __DATABASE_H
#define __DATABASE_H

#include "KnowledgeBase.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

enum command {
	load,
	dump,
	fact,
	rule,
	query,
	drop,
	fail
};

class Database{

private:

	KnowledgeBase* KB;
	std::map <string, command> commandList;

public:

	Database();
	void Parse(string input);
	void Load(string fileName);
	void Dump(string fileName);
	void MakeFact(string params);
	void MakeRule(string params);
	void Query(string params);
	void Drop(string params);
	command Command(string word);

protected:

};


#endif