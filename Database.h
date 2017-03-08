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
	vector<map<string, string> > OR(bool printOut, bool t, Rule* rule, string rName, string fName, vector <string> n, vector<string> uP, vector<map<string, string> > sM, map <int, vector<string> > l, map<string, string> fM);
	void printFact(bool printOut, string name, string fact, vector<string> ruleParams, map<string, string> factMap, unsigned int smSize);
	void Drop(string params);
	command Command(string word);

protected:

};


#endif