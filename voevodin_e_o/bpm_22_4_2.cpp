#include <iostream>
#include <numbers>
#include <numeric>
#include <fstream>
constexpr double eps = std::numeric_limits<double>::epsilon();
bool is_hit(const double x, const double y) {
	
	bool is_in_circle = std::pow(x, 2) + std::pow(y, 2) <= 1 + eps;
	bool is_upper_part = (y >= 0 - eps && y <= 1 + eps) && (x >= -1 - eps && x <= eps);
	bool is_lower_part = (y >= -1 - eps && y <= eps) && (x >= 0 - eps && x <= 1 + eps);
	bool is_upper_line = (y - x >= 1 - eps);
	bool is_lower_line = (y - x <= -1 + eps);
	return is_in_circle && ((is_upper_part && is_upper_line) || (is_lower_part && is_lower_line));
}

bool program(std::istream& a, std::ostream& b) {
	double x, y;
	
	size_t count_hit = 0;
	size_t counter = 0;
	while (a >> x >> y) {
		bool was_hit = is_hit(x, y);
		count_hit += was_hit;
		++counter;
	}
	try {
		b << static_cast<double>(count_hit) / static_cast<double>(counter);
	}
	catch (...) {
		b << 0;
	}
	return 0;
}

int main(int argc, char* argv[]) {
	if (argc == 1) {
		program(std::cin, std::cout);
	}
	else if (argc == 2) {
		std::ifstream file(argv[1]);
		if (file.is_open()) {
			program(file, std::cout);
		}
		file.close();
	}
	else if (argc == 3) {
		std::ifstream file_to_read(argv[1]);
		std::ofstream file_to_write(argv[2]);
		if (file_to_read.is_open() && file_to_write.is_open()) {
			program(file_to_read, file_to_write);
		}
		file_to_read.close();
		file_to_write.close();
	}
}