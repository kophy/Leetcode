class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &A) {
    if (A.empty() || A[0].empty()) {
      return 0;
    }
    M = A.size();
    N = A[0].size();
    for (int i = 1; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        A[i][j] += min(getOrDefault(A, i - 1, j - 1, INT_MAX),
                       min(getOrDefault(A, i - 1, j, INT_MAX),
                           getOrDefault(A, i - 1, j + 1, INT_MAX)));
      }
    }
    int result = INT_MAX;
    for (int j = 0; j < N; ++j) {
      result = min(result, A[M - 1][j]);
    }
    return result;
  }

private:
  int M, N;

  int getOrDefault(vector<vector<int>> &A, int i, int j, int default_val) {
    return (i >= 0 && i < M && j >= 0 && j < N) ? A[i][j] : default_val;
  }
};
