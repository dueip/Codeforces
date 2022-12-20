#include <iostream>
#include <vector>



int main() {
	const double delta_x = 0.05;
	const double eps = 0.0001;
	for (double x = 0.1; x - eps <= 1; x += delta_x) {
		unsigned long long factorial = 1;
		double x_to_the_power = 1;
		const double x_to_the_power_of_2 = x * x;
		double sum = 0;
		for (unsigned long long i = 0; x_to_the_power / factorial >= eps; ++i) {
			if (i != 0) {
				if (i > 1) {
					factorial = 2 * i * ((2 * i) - 1) * (factorial);
				}
				else {
					factorial = 2 * i * factorial;
				}
				x_to_the_power = x_to_the_power * x_to_the_power_of_2;
				
			}
			sum += x_to_the_power / factorial;
			std::cout << "x = " << x << " Sum of [" << i << "] " << sum << std::endl;
		}
	}
}