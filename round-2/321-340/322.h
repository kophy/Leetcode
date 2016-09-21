class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {

                // if we want to add one coin of value coins[j] and get amount (i), then
                // the amount (i - coins[j]) must be reachable.
                if (i >= coins[j] && dp[i - coins[j]] >= 0) {
                    if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1)
                        dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
        return dp[amount];
    }
};