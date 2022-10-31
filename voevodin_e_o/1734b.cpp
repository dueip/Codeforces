    #include <iostream>
     
    int main()
    {
    	int t = 0;
    	int n = 0;
    	std::cin >> t;
    	while (t--)
    	{
    		std::cin >> n;
    		for (int i = 1; i <= n; ++i) {
    			for (int j = 1; j <= i; ++j) {
    				if (j == 1 || j == i) {
    					std::cout << '1' << ' ';
    				}
    				else {
    					std::cout << '0' << ' ';
    				}
    			}
    			std::cout << "\n";
    		}
    		
    	}
    }
