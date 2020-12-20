class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    int M = matrix.size(), N = matrix[0].size();
    int result = 0;
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (matrix[i][j] == 0) {
          continue;
        }
        dp[i + 1][j + 1] = min(dp[i][j], min(dp[i + 1][j], dp[i][j + 1])) + 1;
        result += dp[i + 1][j + 1];
      }
    }
    return result;
  }
};