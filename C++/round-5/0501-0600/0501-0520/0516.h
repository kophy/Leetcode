class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    string t = s;
    reverse(s.begin(), s.end());
    return lcs(s, t);
  }

 private:
  int lcs(const string &s, const string &t) {
    int M = s.size(), N = t.size();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        dp[i + 1][j + 1] =
            (s[i] == t[j]) ? dp[i][j] + 1 : max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
    return dp[M][N];
  }
};