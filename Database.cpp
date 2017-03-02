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
	vector<string> empty;
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
		Query(params, empty);
		break;
	case drop:
		Drop(params);
		break;
	default:
		if (word != "") cout << "Command not recognized\n"; // if its not an empty line it will return error message
		break;
	}
}

void Database::Load(string fileName) {

	try {
		//remove first space in params
		fileName.erase(0, 1);

		//open file
		std::ifstream infile(fileName.c_str());

		if (infile.good() && fileName.find(".sri") != string::npos) {

			cout << "Loading: " << fileName << endl;

			std::string line;
			//read file line by line and execute lines as commands
			while (std::getline(infile, line)) {
				std::istringstream iss(line);
				Parse(line);
			}

		}
		else if(infile.good()){
			cout << "File is not '.sri'";
		}
		else {
			cout << "File " << fileName << " not found." << endl;
		}
	}
	catch (...) {
		cout << "Load Error: File could not be read\n";
	}
}

void Database::Dump(string fileName) {

	try {
		//remove first space in params
		fileName.erase(0, 1);

		if (fileName.find(".sri") == string::npos) fileName += ".sri";

		cout << "Dumping it in " << fileName << endl;

		//open file for writing
		ofstream SRIFile;
		SRIFile.open(fileName.c_str());

		//get the map of all facts
		map<string, vector<Fact*> > facts;
		facts = KB->GetAllFacts();

		//get the map and vector of all rules
		map < string, vector <Rule*> > rules;
		rules = RB->getAllRules();

		//iterate through the map of facts and print them in correct format
		for (map<string, vector<Fact*> >::iterator itf = facts.begin(); itf != facts.end(); ++itf) {
			//for each fact in the vector of facts in each name
			for (int unsigned i = 0; i < itf->second.size(); i++) {
				//define as fact and put open parentheses
				SRIFile << "FACT " << itf->first << "(";
				//put each of the parameters of each fact into the parentheses
				for (int unsigned j = 0; j < itf->second[i]->GetThings().size(); j++) {
					//put a comma in between each parameter
					if (j > 0) { SRIFile << ", "; }
					SRIFile << itf->second[i]->GetThings()[j];
				}
				SRIFile << ")\n";
			}
		}

		for (map< string, vector <Rule*> >::iterator itr = rules.begin(); itr != rules.end(); ++itr) {
			//for each rule in the vector of rules under a name
			for (int unsigned i = 0; i < itr->second.size(); i++) {
				//define as rule and open preantheses
				SRIFile << "RULE " << itr->first << "(";

				//get the parameters that are associated with the rule
				vector <string> params = itr->second[i]->getRuleParams();
				//print each of these parameters in the first set of parentheses
				for (int unsigned j = 0; j < params.size(); j++) {
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
				map <int, vector <string> > logic;
				vector <string> names;
				logic = itr->second[i]->getParam();
				names = itr->second[i]->getParamName();
				//for each fact/rule in the logic
				for (int unsigned it = 0; it < names.size(); ++it) {
					SRIFile << names[it] << "(";

					//print the parameters of the fact/rule
					for (int unsigned j = 0; j < logic[it].size(); j++) {
						SRIFile << logic[it][j];
						//with commas in between parameters
						if (j < logic[it].size() - 1) {
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

	cout << "Making Fact:" << params << "\n";
	try {
		//remove first space in params
		params.erase(0, 1);

		//the characters up to the first parentheses is the fact name
		unsigned int tail = params.find("(");

		//if no parentheses are found throw error
		if (tail == std::string::npos) throw;
		string factName = params.substr(0, tail);

		//starting at tail, find closing parentheses for end of arguments
		int head = params.find(")", tail);
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
	cout << "Making Rule:" << params << "\n";
	try {
		//remove first space in params
		params.erase(0, 1);

		//the characters up to the first parentheses is the fact name
		unsigned int tail = params.find("(");

		//if no parentheses are found throw error
		if (tail == std::string::npos) throw 1;
		string ruleName = params.substr(0, tail);

		//starting at tail, find closing parentheses for end of stuff
		unsigned int head = params.find(")", tail);
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
		}
		else if (logic.compare("AND") != 0) throw 4; // throws error if logic != OR or AND

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
	}
	catch (out_of_range error) {
		cout << "Arguments past ':-' caused error\n";
		error_caught = true;
	}
	catch (...) {
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

vector< map<string, string> > Database::Query(string params, vector<string> upperParams) {

	// Define it out of the scope of the try catch
	//a sourceMaps is a vector of facts from the same source
	vector<map<string, string> > sourceMaps;
	vector<map <string, string> > factMaps;
	vector<Fact*> factList;

	try {

		//removes space from rule name
		params.erase(0, 1);

		//top determines if this is top layer of recursion
		//lower layers should not create facts
		bool top;

		//the top is the only one to get empty parameters
		if (upperParams.empty()) {
			cout << "Making Inference: ";
			top = true;
		}
		else {
			top = false;
		}

		//get the name of the the rule being queried and the possible new fact name
		string ruleName, newFact;
		int space = params.find(" ");
		ruleName = params.substr(0, space);

		// Checks to see if the Rule exsists
		if (RB->checkRule(ruleName) == -1) throw 1;

		//if no new fact name print output instead
		bool printOutput = false;
		if (space != std::string::npos) {
			newFact = params.substr(space + 1, params.length());
			cout << " in Knowlegebase under " << newFact << endl;
		}
		else {
			printOutput = true;
			cout << " to the user." << endl;
		}

		//fact maps are used to put results into the new facts
		//a factmap is a specific fact
		map<string, string> factMap;

		//get the list of rules with the name we are querying
		vector<Rule*> ruleList = RB->getRule(ruleName);

		//for each rule with that name
		for (unsigned int r = 0; r < ruleList.size(); r++) {
			Rule* thisRule = ruleList[r];

			//get operator (AND/OR)
			string operation = thisRule->getLogic();

			map <int, vector<string> > logic = thisRule->getParam();
			vector <string> name = thisRule->getParamName();

			if (operation == "OR") {
				//get each fact/rule in this rule logic
				for (unsigned int it = 0; it < name.size(); it++) {
					factList = KB->getFacts(name[it]);

					//if not a fact, it is a rule
					if (factList.empty()) {

						if (RB->checkRule(name[it]) == -1) throw 2;

						//call a new query and get the results from this rule
						string newQuery = " ";
						newQuery += name[it];
						newQuery += " ";
						if (!printOutput) {
							newQuery += newFact;
						}
						//recursively call query to get sourceMaps from it
						sourceMaps = Query(newQuery, logic[it]);

						//get params of this rule
						vector<string> ruleParams = thisRule->getRuleParams();

						//read from factMap using the rule parameters
						//for each fact map from recursive query
						if (top) {
							if (printOutput) {

								for (unsigned int fm = 0; fm < sourceMaps.size(); fm++) {
									cout << ruleName << newFact << "(";
									factMap = sourceMaps[fm];
									//use the fact map to map things from the fact to the rule
									for (unsigned int i = 0; i < factMap.size(); i++) {
										cout << factMap[ruleParams[i]];
										if (i < factMap.size() - 1) {
											cout << ", ";
										}
									}
									cout << ")\n";
								}
							}
							else {

								string str = "";

								for (unsigned int fm = 0; fm < sourceMaps.size(); fm++) {
									factMap = sourceMaps[fm];
									//use the fact map to map things from the fact to the rule
									for (unsigned int i = 0; i < factMap.size(); i++) {
										str.append(factMap[ruleParams[i]]);
										if (i < factMap.size() - 1) {
											str.append(", ");
										}
									}
								}

								KB->CreateFact(newFact, str);

							}
						}
					}
					else {

						//if it is a fact (OR)
						//get things from each fact with that name
						for (unsigned int f = 0; f < factList.size(); f++) {
							Fact* thisFact = factList[f];

							//take fact parameters and put them in rule parameters
							vector<string> factThings = thisFact->GetThings();
							//create a map from the $params of thisFact
							vector<string> factParamsInRule = logic[it];

							if (top) {
								for (unsigned int i = 0; i < factThings.size() && i < factParamsInRule.size(); i++) {
									factMap[factParamsInRule[i]] = factThings[i];
								}
							}
							else {
								for (unsigned int i = 0; i < factThings.size() && i < upperParams.size(); i++) {
									factMap[upperParams[i]] = factThings[i];
								}
							}

							sourceMaps.push_back(factMap);

							if (top) {
								if (printOutput) {

									//get params of rule
									vector<string> ruleParams = thisRule->getRuleParams();
									//read from factMap using the rule parameters
									cout << ruleName << newFact << "(";
									for (unsigned int i = 0; i < factMap.size(); i++) {
										cout << factMap[ruleParams[i]];
										if (i < factMap.size() - 1) {
											cout << ", ";
										}
									}
									cout << ")\n";

								}
								else {

									// makes a string
									string str = "";

									//get params of rule
									vector<string> ruleParams = thisRule->getRuleParams();

									//read from factMap using the rule parameters
									for (unsigned int i = 0; i < factMap.size(); i++) {
										str.append(factMap[ruleParams[i]]);
										if (i < factMap.size() - 1) {
											str.append(", ");
										}
									}

									KB->CreateFact(newFact, str);

								}
							}
						}
					}
				}
			}
			else {
				//It is AND

				//Create a vector to hold all sourceMaps that will be used to compare sourceMaps together
				vector< vector<map<string, string> > > allMaps;

				//Combine each fact/rule into one FactMap
				for (unsigned int it = 0; it < name.size(); it++) {
					factList = KB->getFacts(name[it]);
					sourceMaps.clear();
					factMap.clear();

					if (factList.empty()) {
						//it is a rule (AND)
						if (RB->checkRule(name[it]) == -1) throw 2;

						//call a new query and get the results from this rule
						string newQuery = " ";
						newQuery += name[it];
						newQuery += " ";
						if (!printOutput) {
							newQuery += newFact;
						}
						//recursively call query to get sourceMaps from it
						sourceMaps = Query(newQuery, logic[it]);
					}
					else {
						//it is a fact (AND)
						//get things from each fact with that name
						for (unsigned int f = 0; f < factList.size(); f++) {
							Fact* thisFact = factList[f];

							//take fact parameters and put them in rule parameters
							vector<string> factThings = thisFact->GetThings();
							//create a map from the $params of thisFact
							vector<string> factParamsInRule = logic[it];

							if (top) {
								for (unsigned int i = 0; i < factThings.size() && i < factParamsInRule.size(); i++) {
									factMap[factParamsInRule[i]] = factThings[i];
								}
							}
							else {
								for (unsigned int i = 0; i < factThings.size() && i < upperParams.size(); i++) {
									factMap[upperParams[i]] = factThings[i];
								}
							}

							sourceMaps.push_back(factMap);
						}
					}

					allMaps.push_back(sourceMaps);
				}
				//find a right match for each left rule
				//vector<vector<map<string, string>>>
				//allMaps->sourceMaps->factmap

				//start at first source for finding matches
				sourceMaps = allMaps[0];

				//for each factmap in the first sourcemap
				for (unsigned int f = 0; f < sourceMaps.size(); f++) {
					//for each factmap in the other sourceMap
					vector<map<string, string> > sourceMaps2 = allMaps[1];
					for (unsigned int s = 1; s < sourceMaps2.size(); s++) {
						factMap = sourceMaps[f];
						map<string, string> factMap2 = sourceMaps2[s];

						//for each thing in factMap2
						for (map<string, string >::iterator itf = factMap2.begin(); itf != factMap2.end(); ++itf) {

							map<string, string>::iterator place = factMap.find(itf->first);

							if (place == factMap.end()) {
								//location is free in factMap
								//put new thing in factMap
								factMap[itf->first] = itf->second;
							}
							else {
								//that location is already taken
								//only continue with current factMap2 if the things are the same
								if (factMap[itf->first].compare(itf->second) != 0) {
									factMap.clear();
									continue;
								}
							}
						}

						//write here if there is a factmap and it is not the same factmap
						if (!factMap.empty()) {
							if (top) {
								if (printOutput) {

									//get params of rule
									vector<string> ruleParams = thisRule->getRuleParams();
									//read from factMap using the rule parameters
									cout << ruleName << newFact << "(";
									for (unsigned int i = 0; i < factMap.size() && i < ruleParams.size(); i++) {
										cout << factMap[ruleParams[i]];
										if (i < factMap.size() - 1 && i < ruleParams.size() - 1) {
											cout << ", ";
										}
									}
									cout << ")\n";

								}
								else {

									// makes a string
									string str = "";

									//get params of rule
									vector<string> ruleParams = thisRule->getRuleParams();

									//read from factMap using the rule parameters
									for (unsigned int i = 0; i < factMap.size() && i < ruleParams.size(); i++) {
										str.append(factMap[ruleParams[i]]);
										if (i < factMap.size() - 1 && i < ruleParams.size() - 1) {
											str.append(", ");
										}
									}

									KB->CreateFact(newFact, str);

								}
							}
						}
					}
				}
			}
		}

		return sourceMaps;
	}
	catch (int e) {
		if (e == 1) cout << "INFERENCE Error: Rule not found." << endl;
		if (e == 2) cout << "INFERENCE Error: Parameter given is neither a rule or a fact." << endl;
	}
	catch (...) {
		cout << "INFERENCE Error: Unknown." << endl;
	}

	return sourceMaps; // If things fail something still get returned
}

void Database::Drop(string params) {
	cout << "Droping:" << params << endl;

	//remove first space in params
	params.erase(0, 1);

	RB->deleteRule(params);
	KB->DeleteFact(params);
}

command Database::Command(string word) {
	//change all characters in string to lowercase
	for (unsigned int i = 0; i < word.length(); ++i) {
		word[i] = tolower(word[i]);
	}
	//check if the command is valid
	map <string, command>::iterator it = commandList.find(word);
	if (it != commandList.end()) {
		//use commandList to get correct function to execute
		return commandList[word];
	}
	else {
		//return invalid command if not recognized
		return fail;
	}
}