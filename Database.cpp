#include "Database.h"

using namespace std;

Database::Database() {
	KB = new KnowledgeBase();
	RB = new RuleBase();

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
	ofstream f;
	f.open(fileName);

	vector <Fact *> facts;
	facts = KB->GetAllFacts();

	map < string, vector <Rule*> > rules;
	rules = RB->getAllRules();

	for (int i = 0; i < facts.size(); i++) {
		vector <string> printer = facts[i]->GetThings();
		for (int j = 0; j < printer.size(); j++) {
			cout << printer[j];
		}
	}

	//for (std::map< string, vector <Rule*> >::iterator it = rules.begin(); it != rules.end(); ++it) {

	//}
}

void Database::MakeFact(string params) {
	cout << "MakeFact\n";
	try {
		//remove first space in params
		params.erase(0, 1);
		//the characters up to the first parentheses is the fact name
		auto tail = params.find("(");
		//if no parentheses are found throw error
		if (tail == std::string::npos) throw;
		string factName = params.substr(0, tail);
		//starting at tail, find closing parentheses for end of arguments
		auto head = params.find(")", tail);
		if (tail == std::string::npos) throw;
		//put all arguments in string and send it to KB->CreateFact
		string args = params.substr(tail + 1, head - tail - 1);
		KB->CreateFact(factName, args);
	}
	catch (...) {
		cout << "Invalid fact syntax";
	}
}

void Database::MakeRule(string params) {
	cout << "MakeRule\n";
	try {
		//remove first space in params
		params.erase(0, 1);
		//the characters up to the first parentheses is the fact name
		auto tail = params.find("(");
		//if no parentheses are found throw error
		if (tail == std::string::npos) throw;
		string ruleName = params.substr(0, tail);
		//starting at tail, find closing parentheses for end of stuff
		auto head = params.find(")", tail);
		if (tail == std::string::npos) throw;
		//put fact stuff in string
		string args = params.substr(tail + 1, head - tail - 1);
		tail = params.find(":-", head);
		if (tail == std::string::npos) throw;
		string logic = params.substr(tail + 4);
		RB->createRule(ruleName, args, logic);
	}
	catch (...) {
		cout << "Invalid rule syntax";
	}
}

void Database::Query(string params) {
	cout << "Query\n";
}

void Database::Drop(string params) {
	cout << "Drop\n";
	RB->deleteRule(params);
	KB->DeleteFact(params);
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