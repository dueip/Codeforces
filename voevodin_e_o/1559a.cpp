    #include <iostream>
    #include <vector>
     
     
    int main()
    {
    	int t = 0;
    	int n = 0;
    	std::cin >> t;
    	while (t--)
    	{
    		std::cin >> n;
    		std::vector<int> a(n);
    		for (int i = 0; i < n; ++i) {
    			std::cin >> a[i];
    		}
    		int ans = a[0];
    		for (int i = 1; i <n; ++i)
    		{
    			ans &= a[i];
    		}
    		std::cout << ans << std::endl;
    	}
    }
