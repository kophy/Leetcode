// First version.
class Solution {
public:
  int dieSimulator(int n, vector<int> &rollMax) {
    vector<vector<int>> dp(n + 1, vector<int>(6, 0));
    for (int j = 0; j < 6; ++j) {
      dp[1][j] = 1;
    }
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < 6; ++j) {
        for (int k = 0; k < 6; ++k) {
          dp[i][j] = (dp[i][j] + dp[i - 1][k]) % M;
          if (j == k) {
            if (i == rollMax[j] + 1) {
              dp[i][j] = (dp[i][j] - 1 + M) % M;
            } else if (i > rollMax[j] + 1) {
              int tmp = 0;
              for (int s = 0; s < 6; ++s) {
                if (s == j) {
                  continue;
                }
                tmp = (tmp + dp[i - rollMax[j] - 1][s]) % M;
              }
              dp[i][j] = (dp[i][j] - tmp + M) % M;
            }
          }
        }
      }
    }
    int result = 0;
    for (int j = 0; j < 6; ++j) {
      result = (result + dp[n][j]) % M;
    }
    return result;
  }

private:
  int M = pow(10, 9) + 7;
};

// Optimized version.
class Solution {
public:
  int dieSimulator(int n, vector<int> &rollMax) {
    // Use column 6 to store the sum of columns 0 ~ 5.
    vector<vector<long>> dp(n + 1, vector<long>(7, 0));
    for (int j = 0; j < 6; ++j) {
      dp[1][j] = 1;
    }
    dp[1][6] = 6;
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < 6; ++j) {
        dp[i][j] = dp[i - 1][6];
        if (i == rollMax[j] + 1) {
          dp[i][j] = (dp[i][j] - 1 + M) % M;
        } else if (i > rollMax[j] + 1) {
          dp[i][j] = (dp[i][j] - dp[(i - rollMax[j] - 1)][6] % M +
                      dp[(i - rollMax[j] - 1)][j] % M + M) %
                     M;
        }
        dp[i][6] = (dp[i][6] + dp[i][j]) % M;
      }
    }
    return dp[n][6];
  }

private:
  int M = pow(10, 9) + 7;
};