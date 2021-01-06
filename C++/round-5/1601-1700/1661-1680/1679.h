class Solution {
 public:
  int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      int current = nums[i];
      int complement = k - current;
      if (count[complement] > 0) {
        // remove complement from the map
        --count[complement];
        ++result;
      } else {
        // add current element in the map
        ++count[current];
      }
    }
    return result;
  }
};