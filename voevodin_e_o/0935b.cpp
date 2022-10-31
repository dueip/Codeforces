    #include <iostream>
    #include <string>
     
     
    int main()
    {
    	int n = 0;
    	int x = 0;
    	int y = 0;
    	std::string s;
    	std::cin >> n;
    	std::cin >> s;
    	int p = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		if (s[i] == 'U') {
    			++y;
    		}
    		else if (s[i] == 'R') {
    			++x;
    		}
    		if (x == y && s[i] == s[i+1]) {
    			++p;
    		}
    	}
    	std::cout << p;
     
    }
