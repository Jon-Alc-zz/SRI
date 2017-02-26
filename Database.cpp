#include "Database.h"

using namespace std;

Database::Database() {
	KB = new KnowledgeBase();

	//initializes command map to point to correct function when called
	commandList["load"] = load;
	commandList["dump"] = dump;
	commandList["fact"] = fact;
	commandList["rule"] = rule;
	commandList["query"] = query;
	commandList["drop"] = drop;
}

void Database::Parse(string input) {
	//creates string stream to read input
	istringstream iss(input);
	string word;
	string params;
	//puts first word into a string
	iss >> word;
	//puts reaminder of command as parameters
	getline(iss, params);
	//use commandList map to figure out which command was specified
	command action = Command(word);
	switch (action) {
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
	cout << "load";
	try {
		//open file
		std::ifstream infile(fileName);

		std::string line;
		//read file line by line and execute lines as commands
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
	//change all characters in string to lowercase
	for (unsigned int i = 0; i < word.length(); ++i) {
		word[i] = tolower(word[i]);
	}
	//check if the command is valid
	auto it = commandList.find(word);
	if (it != commandList.end()) {
		//use commandList to get correct function to execute
		return commandList[word];
	}
	else {
		//return invalid command if not recognized
		return fail;
	}
}