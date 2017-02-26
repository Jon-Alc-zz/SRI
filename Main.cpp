#include "Database.h"

int main() {
	Database* DB = new Database();

	string input;

	while (true) {

		getline(cin, input);
		if (input == "q") break;
		DB->Parse(input);

	}
}