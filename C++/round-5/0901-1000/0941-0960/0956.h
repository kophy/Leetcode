class Solution {
public:
  int tallestBillboard(vector<int> &rods) {
    int sum = accumulate(rods.begin(), rods.end(), 0);
    vector<vector<int>> dp(rods.size() + 1, vector<int>(2 * sum + 1, 0));

    for (int i = 0; i < rods.size(); ++i) {
      for (int j = 0; j < 2 * sum + 1; ++j) {
        if (j != sum && dp[i][j] == 0) {
          continue;
        }
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        dp[i + 1][j + rods[i]] =
            max(dp[i + 1][j + rods[i]], dp[i][j] + rods[i]);
        dp[i + 1][j - rods[i]] = max(dp[i + 1][j - rods[i]], dp[i][j]);
      }
    }

    int max_height = 0;
    for (int i = 0; i < rods.size(); ++i) {
      max_height = max(max_height, dp[i + 1][sum]);
    }
    return max_height;
  }
};
