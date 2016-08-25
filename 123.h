class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        else {
            int K = 2;
            int max_profit = 0;
            vector<vector<int>> dp(K + 1, vector<int>(prices.size(), 0));

            for (int k = 1; k <= K; ++k) {
                int tmpMax = dp[k - 1][0] - prices[0];
                for (int j = 1; j < prices.size(); ++j) {
                    dp[k][j] = max(dp[k][j - 1], prices[j] + tmpMax);
                    max_profit = max(max_profit, dp[k][j]);
                    tmpMax = max(tmpMax, dp[k - 1][j] - prices[j]);
                }
            }
            return max_profit;
        }
    }
};