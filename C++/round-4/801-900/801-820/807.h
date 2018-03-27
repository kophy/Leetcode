class Solution {
 public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    int M = grid.size(), N = grid[0].size();
    vector<int> tb_max(N, INT_MIN), lr_max(M, INT_MIN);
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        tb_max[j] = max(tb_max[j], grid[i][j]);
        lr_max[i] = max(lr_max[i], grid[i][j]);
      }
    }
    int result = 0;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        result += min(tb_max[j], lr_max[i]) - grid[i][j];
      }
    }
    return result;
  }
};
