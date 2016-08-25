class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        return cost(dp, 1, n);
    }

private:
    int cost(vector<vector<int>> &dp, int s, int e) {
        if (s >= e)
            return 0;
        if (dp[s][e])
            return dp[s][e];
        dp[s][e] = INT_MAX;
        for (int i = s; i <= e; ++i) {
            int temp = max(cost(dp, s, i - 1), cost(dp, i + 1, e));
            dp[s][e] = min(dp[s][e], i + temp);
        }
        return dp[s][e];
    }
};