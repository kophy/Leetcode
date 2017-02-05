class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; pow(j, 2) <= i; ++j)
                dp[i] = min(dp[i], dp[i - pow(j, 2)] + 1);
        return dp[n];
    }
};