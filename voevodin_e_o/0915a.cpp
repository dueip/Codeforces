

    #include <iostream>
     
     
     
    int main()
    {
    	int n = 0;
    	int k = 0;
    	int ans = 101;
    	int p = 0;
    	std::cin >> n;
    	std::cin >> k;
    	for (int i = 0; i < n; ++i) 
    	{
    		std::cin >> p;
    		if (k % p == 0) {
    			ans = std::min(ans, k / p);
    		}
    	}
    	std::cout << ans;
     
