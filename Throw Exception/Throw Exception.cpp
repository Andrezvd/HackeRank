// Throw Exception.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <exception>

/* Define the exception here */

class BadLengthException {
public:
	int w;
	BadLengthException(int n) {
		w = n;
	}
	int what() {
		return w;
	}

};


bool checkUsername(std::string username) {
	bool isValid = true;
	int n = username.length();
	if (n < 5) {
		/* APENAS SE EJECUTE ESTE THROW EL TRY LO AGARRA Y EJECUTA EL CATCH*/
		throw BadLengthException(n);
	}
	for (int i = 0; i < n - 1; i++) {
		if (username[i] == 'w' && username[i + 1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; std::cin >> T;
	while (T--) {
		std::string username;
		std::cin >> username;
		try {
			bool isValid = checkUsername(username);
			if (isValid) {
				std::cout << "Valid" << '\n';
			}
			else {
				std::cout << "Invalid" << '\n';
			}
		}
		catch (BadLengthException e) {
			std::cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
