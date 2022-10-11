#include <iostream>

int main() {
	size_t t = 0;
	std::cin >> t;
	for (t; t > 0; --t) {
		bool running = true;
		size_t how_did_it_grow = 0;
		bool today = false;
		bool yesterday = false;
		size_t days = 0;
		std::cin >> days;
		for (size_t i = 0; i < days; ++i) {
			std::cin >> today;
			if (today && !yesterday) {
				how_did_it_grow += 1;
				yesterday = true;
			}
			else if (yesterday && today) {
				how_did_it_grow += 5;
			}
			else if (!today && !yesterday && i != 0) {
				running = false;
			}
			else if (!today) {
				yesterday = false;
			}
		}
		if (running)
			std::cout << 1 + how_did_it_grow << "\n";
		else
			std::cout << "-1\n";
	}
}