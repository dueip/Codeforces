#include <iostream>
#include <vector>
#include <string>

int main() {
	std::string first_word;
	std::string second_word;
	size_t first_word_sub = 0;
	size_t second_word_sub = 0;
	std::cout << "1st word: ";
	std::cin >> first_word;
	std::cout << "2nd word: ";
	std::cin >> second_word;

 
	size_t substr_count = 0;
	for (std::pair<long long, long long> i = { first_word.size() - 1,second_word.size() - 1}; (i.first >= 0 && i.second >= 0); --i.first, --i.second) {
		if (first_word[i.first] != second_word[i.second]) {
			first_word_sub = i.first;
			second_word_sub = i.second;
			break;
		}

	}

	std::cout << first_word.size() + second_word.size() - ((first_word_sub ) + (second_word_sub));

}
