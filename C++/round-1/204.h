class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;
        vector<int> prime(n, 1);
        prime[0] = 0;
        prime[1] = 0;
        for (int i = 2; i < n; ++i) {
            if (prime[i]) {
                for (int j = 2; i * j < n; ++j)
                    prime[i * j] = 0;
            }
        }
        return accumulate(prime.begin(), prime.end(), 0);
    }
};