class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size() && i - coins[j] >= 0; ++j)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
        return (dp[amount] == INT_MAX)? -1 : dp[amount];
    }
};