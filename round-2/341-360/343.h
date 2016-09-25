class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2)
            return 1;
        vector<int> dp(n + 1, 1);
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                dp[i] = max(dp[i], (i - j) * j);        // break directly
                dp[i] = max(dp[i], dp[i - j] * j);      // break recursively
            }
        }
        return dp[n];
    }
};