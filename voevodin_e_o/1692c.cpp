#include <iostream>
#include <vector>
int main() {
	size_t t = 0;
	std::cin >> t;
	for (t; t > 0; --t) {
		std::vector<std::pair<size_t, size_t>> possible_candidates;
		for (size_t y = 0; y < 8; ++y) {
			bool was_attacked_at_this_already = false;
			bool was_attacked_twice = false;
			size_t possible_x = 0;
			for (size_t x = 0; x < 8; ++x) {
				char a;
				bool was_attacked = false;
				
				std::cin >> a;
				was_attacked = (a == '#');

				
				if (was_attacked) {
					was_attacked_at_this_already = true;
					possible_x = x;
				}
				else if (was_attacked && was_attacked_at_this_already) {
					was_attacked_twice = true;
					possible_x = 0;
					break;
				}
			}
			if (y != 0 && y!= 7 && possible_x != 0 && possible_x != 7 && !was_attacked_twice) {
				possible_candidates.push_back(std::pair<size_t, size_t>(y + 1, possible_x + 1));
			}
		}
		for (auto& el : possible_candidates) {
			std::cout << el.first << " " << el.second << '\n';
		}

	}
}