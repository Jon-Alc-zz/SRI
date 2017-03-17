#include "Connection.h"

//Constructor: Call parent Thread Constructor
Connection::Connection(TCPSocket * p_tcpSocket): Thread()
{
 tcpSocket = p_tcpSocket; // Set the TCP socket
 next_connection = NULL; // Set the next pointer to NULL
}

// A modifier that sets the pointer of the next connection
void Connection::setNextConnection(Connection * connection){next_connection = connection;}

// A Selectot that returned a pointer to the next connection
Connection * Connection::getNextConnection (){return next_connection;}

// Destructor: delete the TCP socket if set
Connection::~Connection(){if ( tcpSocket != NULL ) delete (tcpSocket);}

void * Connection::threadMainBody (void * arg) { // Main thread body for serving the connection
	
	SRI(tcpSocket); // Starts the SRI program
	
	tcpSocket->shutDown(); // Shutdown the TCP Socket
	return NULL;
}