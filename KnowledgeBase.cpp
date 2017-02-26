//-----------------------------------
//KnowledgeBase.cpp
//-----------------------------------


#include "KnowledgeBase.h"

KnowledgeBase::KnowledgeBase(){
	
}

int KnowledgeBase::CheckFact(string fact) {
	auto it = KBmp.find(fact);
	if (it != KBmp.end()) {
		return 1;
	}
	else {
		return -1;
	}
}

vector <Fact *> KnowledgeBase::GetAllFacts() {
	return facts;
}

auto KnowledgeBase::getFacts(string fact) {
	try {
		if (CheckFact(fact) == 1) {
			return KBmp[fact];
		}
	}
	catch (...) {
		cout << "getFacts Error: fact" << fact << " not found." << endl;
	}
}

void KnowledgeBase::CreateFact(string name, string things) {
	Fact* newFact = new Fact(things);
	facts.push_back(newFact);
}

void KnowledgeBase::DeleteFact(string fact) {
	it = KBmp.find(fact);
	KBmp.erase(it);
}

KnowledgeBase::~KnowledgeBase() {};