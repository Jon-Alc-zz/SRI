#include "Database.h"
#include "TCPServerSocket.h"
#include "GarbageCollector.h"

int main(int argc, char** argv) {

    // Instantiate a garbage collector object
    GarbageCollector * garbageCollector = new GarbageCollector();

    TCPServerSocket * tcpServerSocket = new TCPServerSocket("127.0.0.1",9999,100);
	
	tcpServerSocket->initializeSocket(); // Initialize the server socket
	
	while (true) {

	    // Wait for connection indefinitely
        TCPSocket * tcpSocket = tcpServerSocket->getConnection(0,0,-1,-1);
		
		if (tcpSocket == NULL) break; // if tcpSocket is NULL then error occured and we break the loop
		
		garbageCollector->cleanup(); // Invoke the garbage collector cleaner in case of expired connections
		
		Connection * c = new Connection (tcpSocket); // Instantiate a new Connection object and pass thereturned TCP socket to it
		
		c->start(); // Start the connection thread to communicate with the client
		
		garbageCollector->addConnection(c);
	}

    delete(garbageCollector);
	delete(tcpServerSocket);

	return(0);
}