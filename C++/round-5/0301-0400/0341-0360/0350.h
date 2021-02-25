class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> count1;
    for (int x : nums1) {
      ++count1[x];
    }
    unordered_map<int, int> count2;
    for (int x : nums2) {
      ++count2[x];
    }

    vector<int> result;
    for (auto [x, c1] : count1) {
      if (!count2.count(x)) {
        continue;
      }
      int c2 = count2[x];
      for (int i = 0; i < min(c1, c2); ++i) {
        result.push_back(x);
      }
    }
    return result;
  }
};