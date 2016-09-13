class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> prime(n, true);

        for (int i = 2; i < n; ++i) {
            if (prime[i]) {
                ++count;
                for (int j = 1; i * j < n; ++j)
                    prime[i * j] = false;
            }
        }
        return count;
    }
};