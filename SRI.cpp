#include "SRI.h"

void SRI(TCPSocket * p_tcpSocket) {
	char file_name[1024]; // A buffer for holding the file name
    int read_bytes;
	
	Database* DB = new Database();

	string input;

	while (true) {
		memset (file_name,0,1024); // Initialize the buffer
		read_bytes = p_tcpSocket→readFromSocket(file_name,1023); 
		
		if(read_bytes > 0){
			
			input = file_name;
			
			if (input == "exit") break;
			else if (input == "clear" || input == "CLS") cout << string(70, '\n');
			else DB->Parse(input);

		}
		
	}

	delete(DB);

	return(0);
}