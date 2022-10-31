#include <iostream>

#include <vector>





int main()
{
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		std::vector<int> s(n);
		int first = 0;
		int second = 0;
		bool f = true;
		for (int i = 0; i < n; ++i) {
			std::cin >> s[i];
			if (s[i] == 0 && f) {
				first = (i - 1);
				f = false;
			}
			}
		for (int i = 0; i < n; ++i) {
			if (s[n - i - 1] == 0) {
				second = n - i;
				break;
			}
		}
			std::cout << second - first << "\n";
	}
}
