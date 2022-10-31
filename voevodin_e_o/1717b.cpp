#include <iostream>

int main()
{
	int n = 0;
	int k = 0;
	int r = 0;
	int c = 0;
	int t = 0;
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k >> r >> c;
		for (int i = 1; i < n+1; ++i) {
			for (int j = 1; j < n+1; ++j) {
				if ((i + j) % k == (r + c) % k) {
					std::cout << "X";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << "\n";
		}
	}

}
