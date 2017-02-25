#include "Database.h"

Database::Database() {
	KB = new KnowledgeBase();
}

void Database::Parse(string input) {

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
		cout << "File could not be read";
	}
}

void Database::Dump(string fileName) {

}

void Database::MakeFact(string params) {

}

void Database::MakeRule(string params) {

}

void Database::Inference(string params) {

}