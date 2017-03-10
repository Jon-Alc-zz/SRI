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
#include <thread>
#include <future>
#include <functional>

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
	mutex mtx;

public:

	Database();
	void Parse(string input);
	void Load(string fileName);
	void Dump(string fileName);
	void MakeFact(string params);
	void MakeRule(string params);
	vector< map< string, string> > Query(string params, vector<string> upperParams);
	void OR(bool printOut, bool t, Rule* rule, vector<Fact*> facts, string rName, string fName, vector <string> n, unsigned int it, vector<string> uP, vector<map<string, string> > &sM, map <int, vector<string> > l, map<string, string> fM);
	void AND(bool printOutput, Rule* thisRule, string ruleName, string newFact, vector <string> name, vector<string> upperParams, vector<map<string, string> > &sourceMaps, map <int, vector<string> > logic);
	void ANDCombine(string name, string newFact, vector<string> logic, vector< vector<map<string, string> > > &allMaps);
	void ANDCompare(vector<map<string, string> > &mapsToPrint, map<string, string> factMap, map<string, string> factMap2);
	void ANDPrintAll(vector<string> upperParams, bool printOutput, string ruleName, string newFact, Rule* thisRule, vector<string> ruleParams, map<string, string> factMap, vector<map<string, string> > &sourceMaps);
	void printFact(bool printOut, string name, string fact, vector<string> ruleParams, map<string, string> factMap, unsigned int smSize);
	void Drop(string params);
	command Command(string word);
	~Database();

};


#endif