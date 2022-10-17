#include <iostream>
#include <string>

int main()
{
	size_t t;
	std::cin >> t;
	bool flag = true;
	for (int q = 0; q < t; q += 1)
	{
		std::string s;
		std::cin >> s;
		for (size_t i = 0; i < s.length(); i += 1) {
			if ((i == 0 || s[i] != s[i - 1]) && (i == s.length() - 1 || s[i] != s[i + 1])) {
				flag = flag;
			}
		}
		if (flag) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
		flag = true;
	}
}
