class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int M = s1.size(), N = s2.size();
        if (s3.size() != M + N)
            return false;
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                if (s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
        return dp[M][N];
    }
};