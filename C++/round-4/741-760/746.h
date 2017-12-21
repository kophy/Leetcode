class Solution {
 public:
  int minCostClimbingStairs(vector<int> &cost) {
    if (cost.size() <= 2) return 0;
    vector<int> dp(cost.size() + 1, 0);
    for (int i = 1; i < cost.size(); ++i)
      dp[i + 1] = min(dp[i] + cost[i], dp[i - 1] + cost[i - 1]);
    return dp[cost.size()];
  }
};
