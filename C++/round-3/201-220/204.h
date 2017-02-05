class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> data(n, true);
        for (int i = 2; i < n; ++i) {
            if (!data[i])
                continue;
            ++count;
            for (int j = 2; i * j < n; ++j)
                data[i * j] = false;
        }
        return count;
    }
};