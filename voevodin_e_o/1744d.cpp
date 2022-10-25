#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
//size_t count(size_t num) {
//	return num % 2 ?  static_cast<size_t>(log2(num));
//}

size_t count2(size_t num) {
	size_t counter = 0;
	while (num % 2 == 0) {
		++counter;
		num /= 2;
	}
	return counter;
}

int main() {
	size_t t = 0;
	std::cin >> t;
	for (t; t > 0; --t) {
		size_t arr_size = 0;
		std::cin >> arr_size;
		
		std::vector<size_t> vec(arr_size);
		for (size_t& el : vec) {
			std::cin >> el;
		}
		/*for (size_t& el : vec) {
			arr_size -= count2(el);
		}*/
		size_t sum = 0;
		size_t count = 0;
		for (size_t i = 0; i < vec.size(); ++i) {
			if (sum != arr_size && (i + 1) % 2 == 0) {
				size_t yeah = static_cast<size_t>(log2(i + 1));
				auto counti = count2(vec[i]);
				if (counti != yeah) {
					sum += yeah;
					count += 1;
				}
				else {
					sum += counti;
				}
			}
		}
		std::cout << arr_size << std::endl;
	}
}
// 1 2
// 3 2 
