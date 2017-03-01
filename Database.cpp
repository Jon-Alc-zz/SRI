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
	commandList["inference"] = inference;
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
	case inference:
		Query(params);
		break;
	case drop:
		Drop(params);
		break;
	default:
		if(word != "") cout << "Command not recognized\n"; // if its not an empty line it will return error message
		break;
	}
}

void Database::Load(string fileName) {
	cout << "Loading: " << fileName << "\n";
	try {
		//remove first space in params
		fileName.erase(0, 1);

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
		cout << "Load Error: File could not be read\n";
	}
}

void Database::Dump(string fileName) {
	cout << "Dumping to " << fileName << "\n";
	try {
		//remove first space in params
		fileName.erase(0, 1);

		//open file for writing
		ofstream SRIFile;
		SRIFile.open(fileName);

		//get the map of all facts
		map<string, vector<Fact*> > facts;
		facts = KB->GetAllFacts();

		//get the map of all rules
		map < string, vector <Rule*> > rules;
		rules = RB->getAllRules();

		//iterate through the map of facts and print them in correct format
		for (map<string, vector<Fact*> >::iterator itf = facts.begin(); itf != facts.end(); ++itf) {
			//for each fact in the vector of facts in each name
			for (int i = 0; i < itf->second.size(); i++) {
				//define as fact and put open parentheses
				SRIFile << "FACT " << itf->first << "(";
				//put each of the parameters of each fact into the parentheses
				for (int j = 0; j < itf->second[i]->GetThings().size(); j++) {
					//put a comma in between each parameter
					if (j > 0) { SRIFile << ", "; }
					SRIFile << itf->second[i]->GetThings()[j];
				}
				SRIFile << ")\n";
			}
		}

		for (map< string, vector <Rule*> >::iterator itr = rules.begin(); itr != rules.end(); ++itr) {
			//for each rule in the vector of rules under a name
			for (int i = 0; i < itr->second.size(); i++) {
				//define as rule and open preantheses
				SRIFile << "RULE " << itr->first << "(";

				//get the parameters that are associated with the rule
				vector <string> params = itr->second[i]->getRuleParams();
				//print each of these parameters in the first set of parentheses
				for (int j = 0; j < params.size(); j++) {
					SRIFile << params[j];
					//put a comma in between each parameter
					if (j < params.size() - 1) {
						SRIFile << ", ";
					}
				}

				SRIFile << "):- ";
				//print the logical operator for the rule (AND/OR)
				SRIFile << itr->second[i]->getLogic() << " ";

				//get the map of facts and rules in the logical part of the rule
				map <string, vector <string> > logic;
				logic = itr->second[i]->getParam();
				//for each fact/rule in the logic
				for (auto it = logic.begin(); it != logic.end(); ++it) {
					SRIFile << it->first << "(";

					//print the parameters of the fact/rule
					for (int j = 0; j < logic[it->first].size(); j++) {
						SRIFile << logic[it->first][j];
						//with commas in between parameters
						if (j < logic[it->first].size() - 1) {
							SRIFile << ", ";
						}
					}
					SRIFile << ") ";
				}
				SRIFile << "\n";
			}
		}

		SRIFile.close();
	}
	catch (...) {
		cout << "Dump Error: Could not write file";
	}
}

void Database::MakeFact(string params) {

	cout << "MakeFact" << params << "\n";
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
		cout << "FACT USAGE: FACT 'factname'(param1, param2, ...)";
	}
}

void Database::MakeRule(string params) {

	bool error_caught = false;
	cout << "MakeRule" << params << "\n";
	try {
		//remove first space in params
		params.erase(0, 1);

		//the characters up to the first parentheses is the fact name
		auto tail = params.find("(");

		//if no parentheses are found throw error
		if (tail == std::string::npos) throw 1;
		string ruleName = params.substr(0, tail);

		//starting at tail, find closing parentheses for end of stuff
		auto head = params.find(")", tail);
		if (head == std::string::npos) throw 2;

		//put fact stuff in string
		string args = params.substr(tail + 1, head - tail - 1);
		tail = params.find(":-", head);

		if (tail == std::string::npos) throw 3;

		// throws out_of_range
		string logic = params.substr(tail + 3, 3);

		if (logic.compare("OR ") == 0) {
			// erase whitespace from logic operator
			int strPos = logic.find(" ");
			logic.erase(strPos);
		} else if (logic.compare("AND") != 0) throw 4; // throws error if logic != OR or AND

		string strTemp = params.substr(tail + 6);

		// erase whitespace
		while (strTemp.find(" ") != string::npos) {
		 	int strPos = strTemp.find(" ");
		 	strTemp.erase(strTemp.begin() + strPos);
		}

		string categories = ""; // will contain the categories used in the rule
		string dollarParams = ""; // will contain the $parameters of the categories
		int leftPos = 0, rightPos = 0;

		while (strTemp.find("(") != string::npos && strTemp.find(")") != string::npos) {

			leftPos = strTemp.find("(");
			rightPos = strTemp.find(")");

			categories += strTemp.substr(0, leftPos) + ", ";
			dollarParams += strTemp.substr(leftPos, rightPos - leftPos + 1) + ", ";
			strTemp.erase(0, rightPos + 1);

			/* debug stuff
			cout << "strTemp: " << strTemp << "\n";
			cout << "categories: " << categories << "\n";
			cout << "params: " << dollarParams << "\n";
			*/
		}
		
		// erases comma and whitespace at the end
		categories.erase(categories.begin() + categories.length() - 2, categories.begin() + categories.length());
		dollarParams.erase(dollarParams.begin() + dollarParams.length() - 2, dollarParams.begin() + dollarParams.length());

		RB->createRule(ruleName, args, logic, categories, dollarParams);

	}

	catch (int errorNum) {
		if (errorNum == 1) cout << "'(' missing from argument\n";
		if (errorNum == 2) cout << "')' missing from argument\n";
		if (errorNum == 3) cout << "':-' missing from argument\n";
		if (errorNum == 4) cout << "Logical operator caused error\n";
		error_caught = true;
	} catch (out_of_range error) {
		cout << "Arguments past ':-' caused error\n";
		error_caught = true;
	} catch (...) {
		cout << "Invalid rule syntax\n";
		error_caught = true;
	}

	// prints usage message if error found
	if (error_caught) {
		cout << "RULE USAGE: Rule 'Name'($'arga', $'argz')"
			<< " :- [-L] 'factNameA'($'arga', $'...')"
			<< " ... 'factNameZ'($'...', $'argz')\n"
			<< "[-L] = Logical operator, OR/AND\n";
	}
}

void Database::Query(string params) {
	cout << "Inference\n";
	params.erase(0, 1);

	string ruleName, newFact;

	auto space = params.find(" ");

	ruleName = params.substr(0, space);
	bool printOutput = false;
	if (space != std::string::npos) {
		newFact = params.substr(space + 1, params.length());
	}
	else {
		printOutput = true;
	}

<<<<<<< HEAD
=======
	//cout << "name: " << ruleName << "\n";
	//if (printOutput == false) {
	//cout << "fact: " << newFact << "\n";
	//}
>>>>>>> 8fa660cd93b5175cd7fee59b969469018ed8a206
	//get the rule we are inferring from
	vector<Rule*> ruleList = RB->getRule(ruleName);
	for (int r = 0; r < ruleList.size(); r++) {
		Rule* thisRule = ruleList[r];

		//get operator
		string operation = thisRule->getLogic();
		//cout << "operator: " << operation << "\n";

		//get each fact/rule
		map <string, vector<string>> logic = thisRule->getParam();

		for (auto it = logic.begin(); it != logic.end(); ++it) {
			//get all facts with name
			vector<Fact*> factList = KB->getFacts(it->first);
			if (factList.empty()) {
				cout << "not a fact";
			}
			//get things from each fact with that name
			for (int f = 0; f < factList.size(); f++) {
				Fact* thisFact = factList[f];

				//take fact parameters and put them in rule parameters
				vector<string> factThings = thisFact->GetThings();
				//create a map from the $params of thisFact
				map<string, string> factMap;
				vector<string> factParamsInRule = it->second;
				for (int i = 0; i < factThings.size(); i++) {
					factMap[factParamsInRule[i]] = factThings[i];
				}

				//get params of rule
				vector<string> ruleParams = thisRule->getRuleParams();

				//read from factMap using the rule parameters
				cout << "FACT " << newFact << "(";
				for (int i = 0; i < factMap.size(); i++) {
					cout << factMap[ruleParams[i]];
					if (i < factMap.size() - 1) {
						cout << ", ";
					}
				}
				cout << ")\n";
			}
		}
	}

	//figure out if it is a fact or a rule
	//if it is a rule, pass it recursively and get results for possible things
	//if it is a fact, do this logic once for each instance of a fact with that name
	//if AND, if any $params between rules/facts contradict one another, stop instance
	//if OR, do it as if it was the only rule/fact, then add all results together
	//put applicable $params into a CreateFact() call
}

void Database::Drop(string params) {
	cout << "Droping " << params << "\n";
	RB->deleteRule(params);
	KB->DeleteFact(params);
}

command Database::Command(string word) {
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