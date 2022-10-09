//#include <iostream>
//#include <numbers>
//
//size_t fact(size_t a) {
//	size_t res = 1;
//	while (a) {
//		res *= a;
//		--a;
//	}
//	return res;
//}
//constexpr auto pi_4 = std::numbers::pi / 4;
//int main() {
//
//	double delta = 0.1;
//	double a = 0;
//	double b = 1;
//	double eps = 0.0001;
//	double sum = 0;
//	for (size_t i = 0;; ++i) {
//		size_t flag = false;
//		for (double x = a; x < b; x += delta) {
//
//			double res = pow(2 * x, i) / static_cast<double>(fact(i));
//			if (res != 0 && abs(res) < eps) {
//				std::cout << pow(std::numbers::e, 2 * x) << std::endl;
//				flag = true;
//				break;
//			}
//			sum += res;
//		}
//		if (flag) {
//			std::cout << sum;
//			return 0;
//		}
//	}
//}