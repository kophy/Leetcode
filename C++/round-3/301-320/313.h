class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> result(n, 1);
        vector<int> counter(primes.size(), 0);
        for (int i = 1; i < n; ++i) {
            result[i] = INT_MAX;
            for (int j = 0; j < primes.size(); ++j)
                result[i] = min(result[i], result[counter[j]] * primes[j]);
            for (int j = 0; j < primes.size(); ++j)
                if (result[i] == result[counter[j]] * primes[j])
                    ++counter[j];
        }
        return result[n - 1];
    }
};