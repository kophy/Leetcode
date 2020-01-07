class Solution {
 public:
  vector<int> circularPermutation(int n, int start) {
    vector<int> gary(1, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = gary.size() - 1; j >= 0; --j) {
        gary.push_back(gary[j] | (1 << i));
      }
    }
    vector<int> result;
    auto iter = find(gary.begin(), gary.end(), start);
    result.insert(result.end(), iter, gary.end());
    result.insert(result.end(), gary.begin(), iter);
    return result;
  }
};