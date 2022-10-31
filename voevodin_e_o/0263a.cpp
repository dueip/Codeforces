    #include <iostream>
    // {1, 4}
    // {2, 2}
    // 
    int main() {
    	constexpr int rows = 5;
    	constexpr int lines = 5;
    	std::pair<int, int> pos = {};
    	std::pair<int, int> center = { 2, 2 };
    	int matrix[rows][lines] = {};
    	for (int i = 0; i < rows; ++i) {
    		std::cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2] >> matrix[i][3] >> matrix[i][4];
    	}
    	for (int i = 0; i < rows; ++i) {
    		for (int j = 0; j < lines; ++j) {
    			if (matrix[i][j] == 1) {
    				pos = { i, j };
    			}
    		}
    	}
    	std::cout << std::abs(pos.first - center.first) + std::abs(pos.second - center.second);
    }
