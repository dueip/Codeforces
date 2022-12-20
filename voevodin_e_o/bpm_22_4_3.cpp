#include <iostream>
#include <vector>
#include <string>

int main() {
	std::string first_word;
	std::string second_word;
	size_t first_word_sub = std::string::npos;
	size_t second_word_sub = std::string::npos;
	std::cout << "1st word: ";
	std::cin >> first_word;
	std::cout << "2nd word: ";
	std::cin >> second_word;
	if (first_word.size() < second_word.size()) {
		std::string c = first_word;
		first_word = second_word;
		second_word = c;
	}

	// Что-то я сглупил надо было с конца идти да...
 
	size_t substr_count = 0;
	for (size_t i = 0; i < first_word.size(); ++i) {
		for (size_t j = i; j < second_word.size(); ++j) {
			if (first_word[i] == second_word[j]) {
				if (first_word_sub == std::string::npos && second_word_sub == std::string::npos || first_word_sub < second_word_sub) {
					substr_count += 1;
					first_word_sub = i;
					second_word_sub = j;
				}
				break;
			}
			else {
				first_word_sub = std::string::npos;
				second_word_sub = std::string::npos;
			}
		}

	}

	if (first_word_sub != std::string::npos) {
		std::cout << first_word_sub + second_word_sub;
	}
	else {
		std::cout << "0";
	}

}
