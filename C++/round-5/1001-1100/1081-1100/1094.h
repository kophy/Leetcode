class Solution {
 public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    map<int, int> diffs;
    for (const auto &trip : trips) {
      diffs[trip[1]] += trip[0];
      diffs[trip[2]] -= trip[0];
    }

    int current = 0;
    for (const auto &[_, d] : diffs) {
      current += d;
      if (current < 0 || current > capacity) {
        return false;
      }
    }
    return true;
  }
};