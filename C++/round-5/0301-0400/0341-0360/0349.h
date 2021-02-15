class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> nums1_set(nums1.begin(), nums1.end());
    unordered_set<int> nums2_set(nums2.begin(), nums2.end());
    vector<int> result;
    for (int x : nums1_set) {
      if (nums2_set.count(x)) {
        result.push_back(x);
      }
    }
    return result;
  }
};