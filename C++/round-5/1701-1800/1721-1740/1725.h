class Solution {
 public:
  int countGoodRectangles(vector<vector<int>> &rectangles) {
    int largest_square = 0;
    for (const auto &r : rectangles) {
      largest_square = max(largest_square, min(r[0], r[1]));
    }
    int result = 0;
    for (const auto &r : rectangles) {
      if (largest_square == min(r[0], r[1])) {
        ++result;
      }
    }
    return result;
  }
};