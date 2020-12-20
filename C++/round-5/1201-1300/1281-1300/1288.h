class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b) -> bool {
           return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
         });

    int last = 0;
    int result = 1;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[last][1] >= intervals[i][1]) {
        continue;
      } else {
        last = i;
        ++result;
      }
    }
    return result;
  }
};