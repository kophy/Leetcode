class Solution {
 public:
  int dominantIndex(vector<int> &nums) {
    if (nums.size() == 1) return 0;
    int idx1 = (nums[0] > nums[1]) ? 0 : 1, idx2 = 1 - idx1;
    for (int i = 2; i < nums.size(); ++i) {
      if (nums[i] >= nums[idx1]) {
        idx2 = idx1;
        idx1 = i;
      } else if (nums[i] > nums[idx2])
        idx2 = i;
    }
    return (nums[idx1] >= 2 * nums[idx2]) ? idx1 : -1;
  }
};
