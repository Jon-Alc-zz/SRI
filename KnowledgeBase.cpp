//-----------------------------------
//KnowledgeBase.cpp
//-----------------------------------


#include "KnowledgeBase.h"

KnowledgeBase::KnowledgeBase(){
	
}

vector <Fact *> KnowledgeBase::GetAllFacts() {
	return facts;
}

Fact* KnowledgeBase::getFacts(string fact) {
	return facts[1];
}

void KnowledgeBase::CreateFact(string name, string things) {
	Fact* newFact = new Fact(things);
	facts.push_back(newFact);
}

void KnowledgeBase::DeleteFact(string fact) {

}