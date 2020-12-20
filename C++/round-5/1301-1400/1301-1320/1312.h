class Solution {
public:
  int minInsertions(string s) {
    string t = s;
    reverse(s.begin(), s.end());
    return s.size() - lcs(s, t);
  }

private:
  int lcs(const string &s, const string &t) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < t.size(); ++j) {
        dp[i + 1][j + 1] =
            (s[i] == t[j]) ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
    return dp[s.size()][t.size()];
  }
};