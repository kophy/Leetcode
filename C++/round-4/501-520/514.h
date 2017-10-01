class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int M = key.size(), N = ring.size();
        vector<vector<int>> dp(M + 1, vector<int>(N, 0));
        
        // build key from last character to first
        for (int i = M - 1; i >= 0; --i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < N; ++k) {
                    if (ring[k] == key[i]) {
                        int diff = abs(j - k);
                        int step = min(diff, N - diff);
                        dp[i][j] = min(dp[i][j], step + dp[i + 1][k]);
                    }
                }
            }
        }
        return dp[0][0] + M;
    }
};