OBJS = Main.o Database.o KnowledgeBase.o RuleBase.o Fact.o Rule.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++11 -lpthread -c $(DEBUG)
LFLAGS = -Wall -std=c++11 -lpthread $(DEBUG)

sriTest : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o sriTest
	
Main.o : Main.cpp Database.h Database.cpp KnowledgeBase.h KnowledgeBase.cpp RuleBase.h RuleBase.cpp Fact.h Fact.cpp Rule.h Rule.cpp
	$(CC) $(CFLAGS) Main.cpp

Database.o : Database.h Database.cpp KnowledgeBase.h KnowledgeBase.cpp RuleBase.h RuleBase.cpp Fact.h Fact.cpp Rule.h Rule.cpp
	$(CC) $(CFLAGS) Database.cpp

KnowledgeBase.o : KnowledgeBase.h KnowledgeBase.cpp Fact.h Fact.cpp 
	$(CC) $(CFLAGS) KnowledgeBase.cpp
	
RuleBase.o : RuleBase.h RuleBase.cpp Rule.h Rule.cpp
	$(CC) $(CFLAGS) RuleBase.cpp
	
Rule.o : Rule.h Rule.cpp
	$(CC) $(CFLAGS) Rule.cpp
	
Fact.o : Fact.h Fact.cpp
	$(CC) $(CFLAGS) Fact.cpp
	
clean:
	\rm *.o sriTest
