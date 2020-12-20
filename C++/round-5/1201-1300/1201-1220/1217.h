class Solution {
public:
  int minCostToMoveChips(vector<int> &chips) {
    vector<int> result(2, 0);
    for (int chip : chips) {
      ++result[chip % 2];
    }
    return min(result[0], result[1]);
  }
};