class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int result = 0;
    for (int i = 0; i < (int)points.size() - 1; ++i) {
      int v = abs(points[i][0] - points[i + 1][0]);
      int h = abs(points[i][1] - points[i + 1][1]);
      result += max(v, h);
    }
    return result;
  }
};