#include "Database.h"

using namespace std;

Database::Database() {
	KB = new KnowledgeBase();

	commandList["load"] = load;
	commandList["dump"] = dump;
	commandList["fact"] = fact;
	commandList["rule"] = rule;
	commandList["query"] = query;
	commandList["drop"] = drop;
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
	cout << "Dump\n";
	cout << fileName << endl;
}

void Database::MakeFact(string params) {
	cout << "MakeFact\n";
	//get information from params
	//then call KB->CreateFact() with proper arguments
}

void Database::MakeRule(string params) {
	cout << "MakeRule\n";
}

void Database::Query(string params) {
	cout << "Query\n";
}

void Database::Drop(string params) {
	cout << "Drop\n";
}

command Database::Command(string word) {
	cout << "Command\n";
	for (unsigned int i = 0; i < word.length(); ++i) {
		word[i] = tolower(word[i]);
	}
	return commandList[word];
}