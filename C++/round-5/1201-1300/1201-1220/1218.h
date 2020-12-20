class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    int result = 0;
    unordered_map<int, int> dp;
    for (int x : arr) {
      auto iter = dp.find(x - difference);
      int length = (iter == dp.end() ? 1 : iter->second + 1);
      dp[x] = max(dp[x], length);
      result = max(result, length);
    }
    return result;
  }
};