class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    unordered_map<int, int> product_count;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        ++product_count[nums[i] * nums[j]];
      }
    }

    int result = 0;
    for (const auto& p : product_count) {
      result += p.second * (p.second - 1) * 4;
    }
    return result;
  }
};