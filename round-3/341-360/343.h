class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                int temp = max(j, dp[j]) * max(i - j, dp[i - j]);
                dp[i] = max(dp[i], temp);
            }
        }
        return dp[n];
    }
};