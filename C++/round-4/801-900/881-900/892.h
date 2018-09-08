class Solution {
 public:
  int surfaceArea(vector<vector<int>> &grid) {
    int surface = 0;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        // special case: no surface
        if (grid[i][j] == 0) {
          continue;
        }
        // top and bottom
        surface += 2;
        // check 4 neighbors
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k], nj = j + dy[k];
          if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size()) {
            surface += grid[i][j];
          } else {
            surface += max(grid[i][j] - grid[ni][nj], 0);
          }
        }
      }
    }
    return surface;
  }
};
