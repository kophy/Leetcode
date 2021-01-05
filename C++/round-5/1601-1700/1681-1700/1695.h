class Solution {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> window;
    int current_score = 0, max_score = 0;
    int begin = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      while (window.count(num)) {
        window.erase(nums[begin]);
        current_score -= nums[begin];
        ++begin;
      }
      window.insert(num);
      current_score += num;
      max_score = max(max_score, current_score);
    }
    return max_score;
  }
};