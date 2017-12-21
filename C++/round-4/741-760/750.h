class Solution {
 public:
  int countCornerRectangles(vector<vector<int>> &grid) {
    int M = grid.size(), N = grid[0].size();
    int result = 0;
    for (int i = 0; i < M; ++i) {
      for (int j = i + 1; j < M; ++j) {
        int count = 0;
        for (int k = 0; k < N; ++k)
          if (grid[i][k] == 1 && grid[j][k] == 1) ++count;
        // choices for left and right corner
        result += count * (count - 1) / 2;
      }
    }
    return result;
  }
};
