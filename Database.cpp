#include "Database.h"

using namespace std;

Database::Database() {
	KB = new KnowledgeBase();

	commandList["LOAD"] = load;
	commandList["DUMP"] = dump;
	commandList["FACT"] = fact;
	commandList["Rule"] = rule;
	commandList["QUERY"] = query;
	commandList["DROP"] = drop;
}

void Database::Parse(string input) {
	istringstream iss(input);
	string word;
	string params;
	iss >> word;
	getline(iss, params);
	switch (Command(word)) {
	case load:
		Load(params);
		break;
	case dump:
		Dump(params);
		break;
	case fact:
		MakeFact(params);
		break;
	case rule:
		MakeRule(params);
		break;
	case query:
		Query(params);
		break;
	case drop:
		Drop(params);
		break;
	default:
		cout << "command not recognized\n";
		break;
	}
}

void Database::Load(string fileName) {
	try {
		std::ifstream infile(fileName);

		std::string line;
		while (std::getline(infile, line)) {
			std::istringstream iss(line);
			Parse(line);
		}
	}
	catch(...){
		cout << "File could not be read\n";
	}
}

void Database::Dump(string fileName) {
	cout << "Dump";
}

void Database::MakeFact(string params) {
	cout << "MakeFact";
	//get information from params
	//then call KB->CreateFact() with proper arguments
}

void Database::MakeRule(string params) {
	cout << "MakeRule";
}

void Database::Query(string params) {
	cout << "Query";
}

void Database::Drop(string params) {
	cout << "Drop";
}

command Database::Command(string word) {
	cout << "Command";
	return commandList[word];
}