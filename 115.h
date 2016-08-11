class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if(len1 == 0 || len2 == 0)
            return 0;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= len1; ++i) {
            dp[i][0] = 1;
            for(int j = 1; j <= min(i, len2); ++j) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[len1][len2];
    }
};