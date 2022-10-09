//#include <iostream>
//#include <cmath>
//
//size_t fact(size_t a) {
//	size_t res = 1;
//	while (a) {
//		res *= a;
//		--a;
//	}
//	return res;
//}
//
//int main()
//{
//	double delta = 0.1;
//	double a = -1;
//	double b = 1;
//	double eps = 0.001;
//	double sum = 0;
//	for (size_t i = 0;; ++i) {
//		int what_to_mult_by = (i % 2 == 0 ? 1 : -1);
//		bool flag = false;
//		for (double x = a; x < b; x += delta) {
//			
//			double res = what_to_mult_by * (pow(x, 2 * i) / fact(2 * i));
//			if (abs(res) < eps) {
//				std::cout << cos(x) << std::endl;
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
//
//}