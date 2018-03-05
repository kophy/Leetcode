class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int M = s1.size(), N = s2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        
        // 1. when s1 is empty
        for (int j = 0; j < N; ++j)
            dp[0][j + 1] = dp[0][j] + s2[j];
        
        // 2. when s2 is empty
        for (int i = 0; i < M; ++i)
            dp[i + 1][0] = dp[i][0] + s1[i];
        
        // 3. both s1 and s2 are non-empty
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (s1[i] == s2[j])
                    dp[i + 1][j + 1] = dp[i][j];
                else 
                    dp[i + 1][j + 1] = min(dp[i][j + 1] + s1[i], dp[i + 1][j] + s2[j]);
            }
        }
        return dp[M][N];
    }
};