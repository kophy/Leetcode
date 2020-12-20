class Solution {
public:
  int numEnclaves(vector<vector<int>> &A) {
    if (A.empty() || A[0].empty()) {
      return 0;
    }
    M = A.size();
    N = A[0].size();

    for (int i = 0; i < M; ++i) {
      dfs(A, i, 0);
      dfs(A, i, N - 1);
    }
    for (int j = 0; j < N; ++j) {
      dfs(A, 0, j);
      dfs(A, M - 1, j);
    }
    int enclaves = 0;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (A[i][j] == 1) {
          ++enclaves;
        }
      }
    }
    return enclaves;
  }

private:
  int M, N;

  void dfs(vector<vector<int>> &A, int i, int j) {
    if (i < 0 || i >= M || j < 0 || j >= N || A[i][j] != 1) {
      return;
    }
    A[i][j] = 2;
    dfs(A, i + 1, j);
    dfs(A, i - 1, j);
    dfs(A, i, j + 1);
    dfs(A, i, j - 1);
  }
};
