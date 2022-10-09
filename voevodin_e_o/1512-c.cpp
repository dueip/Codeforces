//#include <iostream>
//#include <string>
//#include <vector>
//
//size_t [[nodiscard]] count(const std::string& str, char what_to_count) {
//	size_t counter = 0;
//	for (const auto& el : str) {
//		if (el == what_to_count)
//			++counter;
//	}
//	return counter;
//}
//
//bool flag = false;
//
//void wrong_answer() {
//	std::cout << "-1" << std::endl;
//	flag = true;
//}
//
//int main() {
//
//	// Ситуация с серединой
//	
//	size_t t;
//	std::cin >> t;
//	size_t count_repl = 0;
//	//size_t input.size();
//	for (int j = 0; j < t; ++j) {
//
//		size_t max_as = 0;
//		size_t max_bs = 0;
//		std::cin >> max_as >> max_bs;
//		std::string input;
//		std::cin >> input;
//
//		size_t as = max_as - count(input, '0');
//		size_t bs = max_bs - count(input, '1');
//		
//
//		for (size_t i = 0; i < input.size() && !flag; ++i) {
//			if (input[i] != input[input.size() - i - 1] && input[i] != '?' && input[input.size() - i - 1] != '?') {
//				wrong_answer();
//			}
//
//			else if (input[i] == '?' && input[input.size() - i - 1] != '?' && (as > 0 || bs > 0)) {
//				if (as > 0) {
//					input[i] = input[input.size() - i - 1]
//				}
//				else if (bs > 0) {
//					input[i] = input[input.size() - i - 1];
//				}
//			}
//		}
//
//
//		for (int i = 0; i < input.size(); ++i) {
//			
//			else if (input[i] == '?') {
//				input[i] = input[input.size() - i - 1];
//				count_repl += 1;
//			}
//			else if (input[input.size() - i - 1] == '?') {
//				input[input.size() - i - 1] = input[i];
//				count_repl += 1;
//			}
//		}
//		if (!flag) {
//			std::cout << "-1";
//		}
//		else {
//			if (count_repl != 0)
//				std::cout << count_repl << " " << input;
//			else {
//				std::cout << "0";
//			}
//		}
//
//
//	}
//
//
//}