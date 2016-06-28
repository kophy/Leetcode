class Solution {
public:
    int numSquares(int n) {
        if (n <= 0)
            return 0;
        vector<int> count(n + 1, INT_MAX);
        count[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                count[i] = min(count[i], count[i - j * j] + 1);
            }
        }
        return count[n];
    }
};