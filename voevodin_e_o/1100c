#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <numbers>
int main() {
	size_t n = 0;
	size_t r = 0;
	std::cin >> n >> r;
	std::cout.precision(30);
	long double alpha = std::numbers::pi / static_cast<double>(n);
	const auto sinalpha = sin(alpha);
	long double R = r * sinalpha / (1 - sinalpha);
	std::cout << R;
}
