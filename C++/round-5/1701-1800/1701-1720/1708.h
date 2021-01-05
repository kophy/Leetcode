class Solution {
 public:
  vector<int> largestSubarray(vector<int>& nums, int k) {
    vector<int> max_indices;
    int max_num = INT_MIN;
    for (int i = 0; i <= (int)nums.size() - k; ++i) {
      if (nums[i] > max_num) {
        max_num = nums[i];
        max_indices = {i};
      } else if (nums[i] == max_num) {
        max_indices.push_back(i);
      }
    }

    vector<int> result;
    for (int begin : max_indices) {
      vector<int> temp(nums.begin() + begin, nums.begin() + begin + k);
      result = max(result, temp);
    }
    return result;
  }
};