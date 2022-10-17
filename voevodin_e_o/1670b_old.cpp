#include <iostream>
#include <string>
#include <vector>


// iloveslim = s.find('s');
// ilovseslim
// o e
// j11b11l 
// ba11oz1
// s i


// 0010011
// 01
// (0001), (1), (001), (1)
std::string [[nodiscard]] change_all(const std::string& str, char what_to_change, char change_to_what) {
	std::string to_return;
	to_return.reserve(str.size());
	for (const char& el : str) {
		el == what_to_change ? to_return.push_back(change_to_what) : to_return.push_back(el);
	}

	return to_return;
}

int main() {
	size_t t = 0;
	std::cin >> t;
	for (size_t j = 0; j < t; ++j) {
		std::string input;
		size_t input_size;
		std::cin >> input_size;
		std::cin >> input;
		size_t special_characters_size;
		std::cin >> special_characters_size;
		std::vector<char> special_characters;
		special_characters.resize(special_characters_size);
		for (auto& el : special_characters){
			std::cin >> el;
		}
		for (auto& el : special_characters) {
			input = change_all(input, el, '1');
		}

		if (input.find('1') == input.npos) {
			input = "";
		}
		
		size_t counter = 0;
		size_t max_counter = 0;
		for (size_t i = 0; i < input.size(); ++i) {
			if (input[i] != '1') {
				++counter;
			}
			else {
				max_counter = std::max(counter, max_counter);
				counter = 1;
			}
			
		}
		std::cout << max_counter << "\n";
	}
}
