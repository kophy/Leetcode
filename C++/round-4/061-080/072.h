class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, INT_MAX));
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                } else {
                    // same character, no cost at all
                    if (word1[i - 1] == word2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                    // different character, replace
                    else
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    // delete or insert 1 character in word1
                    dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + 1);
                }
            }
        }
        return dp[M][N];
    }
};