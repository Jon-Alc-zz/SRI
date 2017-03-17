OBJS = sriServer.o Connection.o GarbageCollector.o TCPServerSocket.o TCPSocket.o Thread.o SRI.o  Database.o KnowledgeBase.o RuleBase.o Fact.o Rule.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++11 -lpthread -lsocket -c $(DEBUG)
LFLAGS = -Wall -std=c++11 -lpthread -lsocket $(DEBUG)

sriServer : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o sriServer
	
sriServer.o : sriServer.cpp SRI.cpp Connection.cpp Thread.cpp GarbageCollector.cpp TCPServerSocket.cpp TCPSocket.cpp Database.h Database.cpp KnowledgeBase.h KnowledgeBase.cpp RuleBase.h RuleBase.cpp Fact.h Fact.cpp Rule.h Rule.cpp
	$(CC) $(CFLAGS) sriServer.cpp

SRI.o : SRI.cpp Thread.cpp TCPServerSocket.cpp TCPSocket.cpp Database.h Database.cpp KnowledgeBase.h KnowledgeBase.cpp RuleBase.h RuleBase.cpp Fact.h Fact.cpp Rule.h Rule.cpp
	$(CC) $(CFLAGS) SRI.cpp
	
GarbageCollector.o : GarbageCollector.cpp TCPServerSocket.cpp TCPSocket.cpp Connection.cpp Thread.cpp 
	$(CC) $(CFLAGS) GarbageCollector.cpp
	
Connection.o : Connection.cpp TCPServerSocket.cpp TCPSocket.cpp Thread.cpp
	$(CC) $(CFLAGS) Connection.cpp
	
TCPServerSocket.o : TCPServerSocket.cpp TCPSocket.cpp
	$(CC) $(CFLAGS) TCPServerSocket.cpp
	
TCPSocket.o: TCPSocket.cpp
	$(CC) $(CFLAGS) TCPSocket.cpp
	
Thread.o : Thread.cpp
	$(CC) $(CFLAGS) Thread.cpp
	
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
