// Try Catch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>


class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if (A < 0) {
			throw std::invalid_argument("A is negative");
		}
		std::vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if (B == 0) throw 0;
		real = (A / B) * real;
		int ans = v.at(B);
		return real + A - B * ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; std::cin >> T;
	while (T--) {
		long long A, B;
		std::cin >> A >> B;

		/* Enter your code here. */
		try {
			int res = Server::compute(A, B);
			std::cout << res << std::endl;
		}
		catch (const std::bad_alloc& mem) {
			std::cout << "Not enough memory" << std::endl;
		}
		catch (const std::invalid_argument& arr) {
			std::cout << "Exception: " << arr.what() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		catch (const int& e) {
			std::cout << "Other Exception" << std::endl;
		}
	}
	std::cout << Server::getLoad() << std::endl;
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
