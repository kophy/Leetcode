class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int result = 0;
    unordered_map<int, int> presum_count;
    presum_count[0] = 1;
    int presum = 0;

    for (int x : nums) {
      presum += x;
      result += presum_count[presum - k];
      ++presum_count[presum];
    }
    return result;
  }
};