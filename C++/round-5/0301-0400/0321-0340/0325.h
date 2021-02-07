class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    int result = 0;
    unordered_map<int, int> presum_to_index;
    presum_to_index[0] = -1;
    int presum = 0;

    for (int i = 0; i < nums.size(); ++i) {
      presum += nums[i];
      if (presum_to_index.count(presum - k)) {
        result = max(result, i - presum_to_index[presum - k]);
      }
      if (!presum_to_index.count(presum)) {
        presum_to_index[presum] = i;
      }
    }

    return result;
  }
};