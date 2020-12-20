class Solution {
public:
  bool isValidPalindrome(string s, int k) {
    string t = s;
    reverse(t.begin(), t.end());
    return (s.size() - lcs(s, t)) <= k;
  }

private:
  int lcs(const string &s, const string &t) {
    int N = s.size();
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (s[i] == t[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
          dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
      }
    }
    return dp[N][N];
  }
};