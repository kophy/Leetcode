class Solution {
 public:
  double probabilityOfHeads(vector<double>& prob, int target) {
    int N = prob.size();
    vector<vector<double>> dp(N + 1, vector<double>(target + 1, 0.0));
    dp[0][0] = 1.0;
    for (int i = 0; i < N; ++i) {
      dp[i + 1][0] = dp[i][0] * (1 - prob[i]);
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < target; ++j) {
        dp[i + 1][j + 1] = dp[i][j + 1] * (1 - prob[i]) + dp[i][j] * prob[i];
      }
    }
    return dp[N][target];
  }
};