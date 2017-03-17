//-----------------------------------
//GarbageCollector.h
//-----------------------------------

#ifndef __GARBAGECOLLECTOR_H
#define __GARBAGECOLLECTOR_H

#include <vector>
#include <thread>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

#include "Connection.h"

class GarbageCollector{

    private:
        Connection * head;
        Connection * tail;
    public:
        GarbageCollector();
        void addConnection(Connection * connection);
        void cleanup();
        void terminate();
        ~GarbageCollector();
    protected:

};

#endif