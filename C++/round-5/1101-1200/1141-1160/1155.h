class Solution {
public:
  int numRollsToTarget(int d, int f, int target) {
    int M = pow(10, 9) + 7;
    vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= d; ++i) {
      for (int face = 1; face <= f; ++face) {
        for (int j = 0; j <= target - face; ++j) {
          dp[i][j + face] += dp[i - 1][j];
          dp[i][j + face] %= M;
        }
      }
    }
    return dp[d][target];
  }
};