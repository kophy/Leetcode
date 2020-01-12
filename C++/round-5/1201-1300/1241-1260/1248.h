class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int result = 0, odd_count = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (int num : nums) {
      odd_count += num % 2;
      if (m.count(odd_count - k)) {
        result += m[odd_count - k];
      }
      ++m[odd_count];
    }
    return result;
  }
};