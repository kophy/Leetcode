class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    int M = grid.size(), N = grid[0].size();
    int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

    int surface = 0;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        // if grid[i][j] == 0, there is no cube.
        if (grid[i][j] == 0) {
          continue;
        }
        surface += 2;
        for (int k = 0; k < 4; ++k) {
          int ni = i + di[k], nj = j + dj[k];
          int nh = (ni >= 0 && ni < M && nj >= 0 && nj < N) ? grid[ni][nj] : 0;
          surface += max(grid[i][j] - nh, 0);
        }
      }
    }
    return surface;
  }
};
