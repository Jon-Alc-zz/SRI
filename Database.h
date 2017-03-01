//-----------------------------------
//DataBase.h
//-----------------------------------

#ifndef __DATABASE_H
#define __DATABASE_H

#include "KnowledgeBase.h"
#include "RuleBase.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

enum command {
	load,
	dump,
	fact,
	rule,
	inference,
	drop,
	fail
};

class Database{

private:

	KnowledgeBase* KB;
	RuleBase* RB;
	map <string, command> commandList;

public:

	Database();
	void Parse(string input);
	void Load(string fileName);
	void Dump(string fileName);
	void MakeFact(string params);
	void MakeRule(string params);
	vector< map< string, string> > Query(string params, vector<string> upperParams);
	void Drop(string params);
	command Command(string word);

protected:

};


#endif