//-----------------------------------
//KnowledgeBase.cpp
//-----------------------------------


#include "KnowledgeBase.h"

KnowledgeBase::KnowledgeBase(){
	
}

//finds fact by name and sets value in accordance to what is found
//1 if it is found before the end of the map is reached
//-1 otherwise
int KnowledgeBase::CheckFact(string fact) {
    it = KBmp.find(fact);
	if (it != KBmp.end()) {
		return 1;
	}
	else {
		return -1;
	}
}

//returns map of facts 
map<string, vector<Fact*> > KnowledgeBase::GetAllFacts() {
	return KBmp;
}

//uses fact name to return specific fact in map
//try-catch  and uses CheckFact to see if the fact exists in the
//first place, returns error message otherwise
vector<Fact*> KnowledgeBase::getFacts(string fact) {
	vector<Fact*> empty;

	try {
		if (CheckFact(fact) == 1) {
			return KBmp[fact];
		}
		else {
			return KBmp[fact];
		}
	}
	catch (...) {
		cout << "getFacts Error: fact" << fact << " not found." << endl;
	}

	return empty;
}

//if both string parameters are not empty, a new fact is put into
//map, error message displayed otherwise
void KnowledgeBase::CreateFact(string name, string things) {

	if(name.empty() || things.empty()){
		cout << "CreateFact Error: fact parameters" << name << " or" << things << "is empty." << endl;
	}
	else{
		Fact* newFact = new Fact(things);
		KBmp[name].push_back(newFact);
	}
}

//finds fact by name and uses CheckFact to see if it exists
//deletes fact from map if so, displays error message otherwise
void KnowledgeBase::DeleteFact(string fact) {
	it = KBmp.find(fact);
	if(CheckFact(fact) == -1){
		// cout << "DeleteFact Error: fact" << fact << "does not exist or is invalid." << endl;
	}
	else{
		
		vector <Fact*> tempFacts = KBmp[fact];
		for (unsigned int i = 0; i < tempFacts.size(); i++) {
			delete(tempFacts[i]);
		}

		KBmp[fact].clear();
	}
}

//destructor
KnowledgeBase::~KnowledgeBase() {
	//cout << "Knowledge base is gone." << endl;

	map < string, vector <Fact*> > tempMap = GetAllFacts();
	vector <Fact*> tempFacts;

	for (map < string, vector <Fact*> >::iterator it = tempMap.begin(); it != tempMap.end(); ++it) {

		tempFacts = tempMap[it->first];

		for (unsigned int i = 0; i < tempFacts.size(); i++) {
			delete(tempFacts[i]);
		}

	}
};