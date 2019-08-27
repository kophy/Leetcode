class Solution {
 public:
  bool canDivideIntoSubsequences(vector<int>& nums, int K) {
    int max_count = 0;
    unordered_map<int, int> count;
    for (int x : nums) {
      max_count = std::max(max_count, ++count[x]);
    }
    return (nums.size() / max_count >= K);
  }
};
