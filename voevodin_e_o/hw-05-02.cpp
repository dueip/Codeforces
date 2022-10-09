//#include <iostream>
//#include <numbers>
//
//constexpr auto pi_4 = std::numbers::pi / 4;
//int main() {
//
//	double delta = 0.05;
//	double a = 0;
//	double b = 1;
//	double eps = 0.001;
//	double sum = 0;
//	for (size_t i = 1;; ++i) {
//		bool flag = false;
//		double needed_sin = sin(i * pi_4);
//
//		for (double x = a; x < b; x += delta) {
//			// Rewrite
//			double res = x * ;
//			if (abs(res) < eps && i % 4 != 0) {
//				std::cout << (x * sin(pi_4)) / (1 - 2 * x * cos(pi_4)) << std::endl;
//				flag = true;
//				break;
//			}
//			sum += res;
//			double got_sin = x
//		}
//		if (flag) {
//			std::cout << sum;
//			return 0;
//
//		}
//	}	
//}