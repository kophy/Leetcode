class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }
    M = matrix.size();
    N = matrix[0].size();

    vector<vector<int>> memo(M, vector<int>(N, 0));
    int result = 1;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        result = max(result, dfs(matrix, memo, i, j));
      }
    }
    return result;
  }

 private:
  int M, N;

  int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int i,
          int j) {
    if (memo[i][j] > 0) {
      return memo[i][j];
    }
    memo[i][j] = 1;
    int di[4] = {0, -1, 0, 1}, dj[4] = {-1, 0, 1, 0};
    for (int k = 0; k < 4; ++k) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni >= 0 && ni < M && nj >= 0 && nj < N &&
          matrix[i][j] < matrix[ni][nj]) {
        memo[i][j] = max(memo[i][j], dfs(matrix, memo, ni, nj) + 1);
      }
    }
    return memo[i][j];
  }
};