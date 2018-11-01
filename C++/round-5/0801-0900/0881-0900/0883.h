class Solution {
 public:
  int projectionArea(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    int M = grid.size(), N = grid[0].size();
    int result = 0;
    vector<int> col_max(M, 0), row_max(N, 0);
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (grid[i][j] > 0) {
          ++result;
          col_max[i] = max(col_max[i], grid[i][j]);
          row_max[j] = max(row_max[j], grid[i][j]);
        }
      }
    }
    result += accumulate(col_max.begin(), col_max.end(), 0) +
              accumulate(row_max.begin(), row_max.end(), 0);
    return result;
  }
};
