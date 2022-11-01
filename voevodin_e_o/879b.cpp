#include <iostream>


int main() {
	int n = 0;
	size_t k = 0;
	std::cin >> n;
	std::cin >> k;
	int curr_win_power = 0;
	int prev_dude_power = 0;
	size_t curr_wins = 0;
	for (int i = 0; i < n; ++i) {
		int curr_power = 0;
		std::cin >> curr_power;
		
		if (curr_wins >= k) {
			break;
		}

		if (prev_dude_power == 0) {
			prev_dude_power = curr_power;
			continue;
		}

		else {
			if (prev_dude_power > curr_power) {
				curr_win_power = prev_dude_power;
				++curr_wins;
			}
			else {
				curr_win_power = curr_power;
				prev_dude_power = curr_power;
				curr_wins = 1;
			}
		}
		//prev_dude_power = curr_power;
	}
	std::cout << curr_win_power;
}
