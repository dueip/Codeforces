    #include <iostream>
    #include <vector>
     
     
    int main()
    {
    	int t = 0;
    	std::cin >> t;
    	while (t--) {
    		int m = 0;
    		int n = 0;
    		int min_h = 1000;
    		int min_l = 1000;
    		int h = 1000;
    		int l = 1000;
    		std::cin >> n;
    		std::cin >> m;
    		for (int i = 0; i < n; ++i) {
    			std::string s;
    			std::cin >> s;
    			for (int j = 0; j < m; ++j) {
    				if (s[j] == 'R') {
    					min_h = std::min(min_h, i);
    					min_l = std::min(min_l, j);
    					if (i < h && j < l) {
    						h = i;
    						l = j;
    					}
    				}
    			}
    		}
    		if (min_h == h && min_l == l) {
    			std::cout << "YES\n";
    		}
    		else {
    			std::cout << "NO\n";
    		}
    	}
    }
