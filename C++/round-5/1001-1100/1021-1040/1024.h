class Solution {
 public:
  int videoStitching(vector<vector<int>> &clips, int T) {
    sort(clips.begin(), clips.end(),
         [](const vector<int> &a, const vector<int> &b) -> bool {
           return a[0] < b[0];
         });
    int count = 0;
    int i = 0, end = 0;
    while (i < clips.size()) {
      if (clips[i][0] > end) {
        return -1;
      }
      // choose the reachable clip with largest end timestamp.
      int next_end = end;
      while (i < clips.size() && clips[i][0] <= end) {
        next_end = max(next_end, clips[i][1]);
        ++i;
      }
      ++count;
      end = next_end;
      if (end >= T) {
        break;
      }
    }
    return (end < T) ? -1 : count;
  }
};
