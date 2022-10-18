#include <iostream>
#include <string>

int main() {
	size_t t;
	std::cin >> t;
	std::string input;
	for (t; t > 0; --t) {
		std::cin >> input;
		
		size_t left_horizon = input.find_last_of('1');
		size_t right_horizon = input.find_first_of('0');

		std::cout << (right_horizon != input.npos ? right_horizon : input.size() - 1) - (left_horizon != input.npos ? left_horizon : 0) + 1;
		std::cout << "\n";
	}
}
