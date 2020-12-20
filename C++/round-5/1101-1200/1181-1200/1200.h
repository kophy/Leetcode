class Solution {
public:
  int countVowelPermutation(int n) {
    vector<vector<long>> dp(n + 1, vector<long>(5, 0));
    for (int j = 0; j < 5; ++j) {
      dp[1][j] = 1;
    }
    for (int i = 2; i <= n; ++i) {
      dp[i][0] = ((dp[i - 1][1] + dp[i - 1][2]) % M + dp[i - 1][4]) % M;
      dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % M;
      dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % M;
      dp[i][3] = (dp[i - 1][2]) % M;
      dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % M;
    }
    int result = 0;
    for (int j = 0; j < 5; ++j) {
      result = (result + dp[n][j]) % M;
    }
    return result;
  }

private:
  int M = pow(10, 9) + 7;
};