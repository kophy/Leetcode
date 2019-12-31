class Solution {
 public:
  int getMaximumGold(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    M = grid.size();
    N = grid[0].size();
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    int result = 0;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        result = max(result, dfs(grid, visited, i, j));
      }
    }
    return result;
  }

 private:
  int M, N;

  int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i,
          int j) {
    if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 0 ||
        visited[i][j]) {
      return 0;
    }
    visited[i][j] = true;
    int max_rest =
        max(max(dfs(grid, visited, i + 1, j), dfs(grid, visited, i - 1, j)),
            max(dfs(grid, visited, i, j + 1), dfs(grid, visited, i, j - 1)));
    visited[i][j] = false;
    return grid[i][j] + max_rest;
  }
};