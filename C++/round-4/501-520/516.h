class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return longestSubSequence(s, t);
    }
    
private:
    int longestSubSequence(string &s, string &t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < t.size(); ++j) {
                if (s[i] == t[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[M][N];
    }
};