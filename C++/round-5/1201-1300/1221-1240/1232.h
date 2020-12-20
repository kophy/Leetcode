class Solution {
public:
  bool checkStraightLine(vector<vector<int>> &coordinates) {
    for (int i = 2; i < coordinates.size(); ++i) {
      if (!check(coordinates[0], coordinates[1], coordinates[i])) {
        return false;
      }
    }
    return true;
  }

private:
  bool check(vector<int> &p1, vector<int> &p2, vector<int> &p3) {
    return (p1[0] - p2[0]) * (p1[1] - p3[1]) ==
           (p1[0] - p3[0]) * (p1[1] - p2[1]);
  }
};