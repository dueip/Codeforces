    #include <iostream>
    #include <vector>
    #include <cmath>
     
     
     
     
    ptrdiff_t solve() {
    	int n, m, x, y, d;
    	std::cin >> n >> m >> x >> y >> d;
    	if ((y - d <= 1 || x + d >= n) && (y + d >= m || x - d <= 1)) {
    		return -1;
    	}
    	else {
    		return n + m - 2;
    	}
    	
    }
     
     
    int main() {
    	size_t tests = {};
    	std::cin >> tests;
    	for (size_t i = 0; i < tests; ++i) {
    		std::cout << solve() << "\n";
    	}
    }
