class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int suffix_sum = accumulate(nums.begin(), nums.end(), 0);
    vector<int> result(nums.size(), 0);
    int prefix_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int left_count = i;
      int right_count = nums.size() - i;
      result[i] += (nums[i] * left_count - prefix_sum) +
                   (suffix_sum - nums[i] * right_count);
      prefix_sum += nums[i];
      suffix_sum -= nums[i];
    }
    return result;
  }
};