//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main() {
//	size_t size = 0;
//	std::cin >> size;
//	std::vector<std::pair<size_t, size_t>> numbers(size);
//	for (auto& el : numbers) {
//		std::cin >> el.first;
//	}
//
//	for (size_t i = 0; i < numbers.size(); ++i) {
//		numbers[i].second = i + 1;
//	}
//
//	
//	std::sort(numbers.begin(), numbers.end(), [](const std::pair<size_t, size_t>& a, const std::pair<size_t, size_t>& b) {
//		return a.first < b.first;
//		});
//	for (auto& el : numbers) {
//		std::cout << el.second << " ";
//	}
//}