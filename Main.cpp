#include "Database.h"

int main() {
	Database* DB = new Database();

	string input;

	while (true) {

		getline(cin, input);
		if (input == "exit") break;
		else if (input == "clear" || input == "CLS") cout << string(70, '\n');
		else DB->Parse(input);
		

	}

	delete(DB);

	return(0);
}