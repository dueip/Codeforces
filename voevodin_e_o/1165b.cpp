    #include <iostream>
    #include <algorithm>
    #include <vector>
     
    // 1 2 3 4
    // 3 1 4 1
    // 2 1 1 1
     
    // 1 1 3 4
    int main() {
    	int n = 0;
    	std::cin >> n;
    	std::vector<int> vec(n);
    	for (auto& el : vec) {
    		std::cin >> el;
    	}
    	std::sort(vec.begin(), vec.end());
    	size_t day_counter = 1;
    	size_t ost = 0;
    	size_t counter = 0;
    	for (const auto& el : vec) {
    		if (el >= day_counter) {
    			//ost += el - day_counter;
    			++day_counter;
    			++counter;
    		}
    		
    		
     
    	}
    	std::cout << counter;
    }
