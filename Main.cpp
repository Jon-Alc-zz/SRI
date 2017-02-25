#include "Database.h"

int main() {
	Database* DB = new Database();

	string input;

	while (true) {

		cin >> input;
		if (input == "q") break;
		DB->Parse(input);

	}
}