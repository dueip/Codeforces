#include <cmath>
#include <iostream>
#include <numbers>
#include <fstream>
#include "geom/Vector.hpp"

Rdec2D calculate_acceleration(const State& dot, const double g) {
	return -g * dot.position / std::pow(length(dot.position), 3);
}

namespace Vector {
	int size(int b) {
		if (b == 0) {
			throw std::exception("Cannot use 0");
		}
		return b;
	}
	int norm()  {
		return 4;
	}
}

int size() {
	return 3;
}


// Моделирование тяготения
int main(int argc, char* argv[]) {
	constexpr double g = 1;
	constexpr double delta_time = 1;


	std::ofstream file_out("coordinates.txt");
	State dot;
	dot.velocity = { std::numbers::pi / 10, 0 };
	dot.radius = { 1, 1 };
	dot.position = { 0, 10 };
	dot.acceleration = { 0, 0 };//calculate_acceleration(dot, g);

	if (file_out.is_open()) {
		for (int i = 0; ; ++i) {
			
			file_out << dot.position.x << " " << dot.position.y << "\n";
			dot.velocity += dot.acceleration * delta_time;
			dot.position += dot.velocity * delta_time;
			dot.acceleration = calculate_acceleration(dot, g);
		}
	}

	file_out.close();
}
