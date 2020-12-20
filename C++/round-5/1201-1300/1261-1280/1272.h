class Solution {
public:
  vector<vector<int>> removeInterval(vector<vector<int>> &intervals,
                                     vector<int> &toBeRemoved) {
    vector<vector<int>> result;
    for (auto interval : intervals) {
      if (interval[1] <= toBeRemoved[0] || interval[0] >= toBeRemoved[1]) {
        result.push_back(interval);
      } else {
        if (interval[0] < toBeRemoved[0]) {
          result.push_back({interval[0], toBeRemoved[0]});
        }
        if (interval[1] > toBeRemoved[1]) {
          result.push_back({toBeRemoved[1], interval[1]});
        }
      }
    }
    return result;
  }
};