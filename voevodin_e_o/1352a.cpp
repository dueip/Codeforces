    #include <iostream>
    #include <string>
     
    std::pair<size_t, std::string> count_rounds(size_t n) {
    	size_t count = 0;
    	std::string to_ret;
    	for (int i = 1; n; n /= 10, ++i) {
    		if (n % 10 != 0) {
    			to_ret += std::to_string(static_cast<int>(n % 10 * pow(10, i) / 10)) + " ";
    			count += 1;
    		}
    	}
    	return { count, to_ret };
    }
     
    int main() {
    	size_t size = {};
    	std::cin >> size;
    	//size_t* numbers = new size_t[size];
    	std::string buffer;
    	for (size_t i = 0; i < size; ++i) {
    		size_t number = {};
    		std::cin >> number;
    		std::pair<size_t, std::string> a = count_rounds(number);
    		buffer += std::to_string(a.first) + "\n" + a.second + "\n";
    	}
    	std::cout << buffer;
    	
    	//delete[] numbers;
    }
