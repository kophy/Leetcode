class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    int N = days.size();
    vector<int> dp(N + 1, INT_MAX);
    dp[N - 1] = costs[0];
    dp[N] = 0;
    for (int i = N - 2; i >= 0; --i) {
      dp[i] = costs[0] + dp[i + 1];
      for (int j = i + 1; j < N; ++j) {
        if (days[i] + 7 > days[j]) {
          dp[i] = min(dp[i], costs[1] + dp[j + 1]);
        } else if (days[i] + 30 > days[j]) {
          dp[i] = min(dp[i], costs[2] + dp[j + 1]);
        }
      }
    }
    return dp[0];
  }
};
