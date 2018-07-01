class Solution {
 public:
  int matrixScore(vector<vector<int>> &A) {
    if (A.empty() || A[0].empty()) return 0;
    int M = A.size(), N = A[0].size();
    int result = 0;
    for (int j = 0; j < N; ++j) {
      // first flip all rows to let all leading digit be 1.
      int same = 0;
      for (int i = 0; i < M; ++i) same += (A[i][j] == A[i][0] ? 1 : 0);
      // then decide whether to flip this column.
      result += max(same, M - same) * (1 << (N - j - 1));
    }
    return result;
  }
};
