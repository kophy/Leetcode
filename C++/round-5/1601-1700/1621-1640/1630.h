class Solution {
 public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                        vector<int>& r) {
    vector<bool> result;
    for (int i = 0; i < l.size(); ++i) {
      result.push_back(
          isArithmeticSubarray({nums.begin() + l[i], nums.begin() + r[i] + 1}));
    }
    return result;
  }

 private:
  bool isArithmeticSubarray(vector<int> data) {
    if (data.size() < 2) {
      return false;
    }
    sort(data.begin(), data.end());
    int diff = data[1] - data[0];
    for (int i = 1; i < data.size(); ++i) {
      if (data[i] - data[i - 1] != diff) {
        return false;
      }
    }
    return true;
  }
};