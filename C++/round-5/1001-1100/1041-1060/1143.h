class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    if (text1.empty() || text2.empty()) {
      return 0;
    }
    int M = text1.size(), N = text2.size();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < text1.size(); ++i) {
      for (int j = 0; j < text2.size(); ++j) {
        if (text1[i] != text2[j]) {
          dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        } else {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        }
      }
    }
    return dp[M][N];
  }
};