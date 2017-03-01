#include "Database.h"

int main() {
	Database* DB = new Database();

	string input;

	while (true) {

		getline(cin, input);
		if (input == "exit") break;
		DB->Parse(input);

	}
}