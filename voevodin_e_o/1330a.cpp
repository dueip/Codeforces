    #include <iostream>
    #include <vector>
    #include <algorithm>
    void solve() {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        std::vector<int> res(500);
        for (int i = 0; i < n; ++i)
            res[a[i] - 1] = 1;
        for (int i = 0; i < res.size() && x > 0; ++i)
            if (!res[i]) {
                res[i] = 1;
                --x;
            }
        for (int i = 0; i < res.size(); ++i)
            if (!res[i]) {
                std::cout << i << std::endl;
                return;
            }
        std::cout << res.size() << std::endl;
    }
    int main()
    {
        int t;
        std::cin >> t;
        for (int i = 0; i < t; ++i) {
            solve();
        }
        return 0;
    }
