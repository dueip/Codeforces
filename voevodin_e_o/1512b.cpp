#include <iostream>
void print_comb(size_t x1, size_t y1, size_t x2, size_t y2, size_t n)
{
	if (y1 == y2) {
		int x3 = x1, y3 = (y1+1)%n, x4 = x2, y4 = (y2 +1)%n;
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < n; j += 1) {
				if ((x1 == j && y1 == i) || (x2 == j && y2 == i)
					|| (x3 == j && y3 == i) || (x4 == j && y4 == i)) {
					std::cout << "*";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << "\n";
		}

	}
	else if (x1 == x2) {
		int x3 = (x1 + 1)%n, y3 = y1, x4 = (x2 + 1)%n, y4 = y2;
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < n; j += 1) {
				if ((x1 == j && y1 == i) || (x2 == j && y2 == i)
					|| (x3 == j && y3 == i) || (x4 == j && y4 == i)) {
					std::cout << "*";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << std::endl;
		}

	}
	else {
		int x3 = x1, y3 = y2, x4 = x2, y4 = y1;
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < n; j += 1) {
				if ((x1 == j && y1 == i) || (x2 == j && y2 == i)
					|| (x3 == j && y3 == i) || (x4 == j && y4 == i)) {
					std::cout << "*";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << "\n";
		}

	}
}

int main()
{
	size_t t;
  size_t n;
	char sym;
	bool flag = true;
	size_t x1, y1, x2, y2;
	std::cin >> t;
	for (size_t q = 0; q < t; q += 1) {
		std::cin >> n;
		x1 = x2 = y1=y2=0;
		for (size_t i = 0; i < n; i += 1) {
			for (size_t j = 0; j < n; j += 1)
			{
				std::cin >> sym;
				if (sym == '*' && flag) {
					x1 = j;
					y1 = i;
					flag = false;
				}
				else if (sym == '*' && !flag) {
					x2 = j;
					y2 = i;
				}
			}

		}
		print_comb(x1, y1, x2, y2, n);
		flag = true;

	}
}
