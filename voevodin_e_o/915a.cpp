#include <iostream>



int main()
{
	int n;
	int k;
	int ans = 101;
	int p = 0;
	std::cin >> n;
	std::com >> k;
	for (int i = 0; i < n; i += 1) 
	{
		std::cin >> p;
		if (k % p == 0) {
			ans = std::min(ans, k / p);
		}
	}
	std::cout << ans;

}
