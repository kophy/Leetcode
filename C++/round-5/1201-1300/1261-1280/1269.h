class Solution {
public:
    int numWays(int steps, int arrLen) {
        int M = pow(10, 9) + 7;
        vector<int> dp(arrLen, 0), next;
        dp[0] = 1;
        
        for (int i = 0; i < steps; ++i) {
            next = dp;
            for (int j = 0; j < arrLen; ++j) {
                if (dp[j] == 0) {
                    break;
                }
                if (j - 1 >= 0) {
                    next[j - 1] += dp[j];
                    next[j - 1] %= M;
                }
                if (j + 1 < arrLen) {
                    next[j + 1] += dp[j];
                    next[j + 1] %= M;
                }
            }
            dp = std::move(next);
        }
        return dp[0];
    }
};