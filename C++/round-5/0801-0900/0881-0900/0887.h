class Solution {
public:
  int superEggDrop(int K, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    for (int m = 1; m <= N; ++m) {
      for (int k = 1; k <= K; ++k) {
        dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
      }
      if (dp[m][K] >= N) {
        return m;
      }
    }
    return -1;
  }
};
