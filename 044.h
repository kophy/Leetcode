class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.size();
        int	len_p = p.size();
        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));

        dp[0][0] = true;
        for (int j = 0; j < len_p; ++j)
            dp[0][j + 1] = dp[0][j] && (p[j] == '*');
        for (int i = 0; i < len_s; ++i) {
            for (int j = 0; j < len_p; ++j) {
                if (p[j] == '*')
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
                else
                    dp[i + 1][j + 1] = dp[i][j] && (p[j] == '?' || s[i] == p[j]);
            }
        }

        return dp[len_s][len_p];
    }
};