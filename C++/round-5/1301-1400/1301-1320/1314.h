class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K) {
    int M = mat.size(), N = mat[0].size();
    vector<vector<int>> sum(M + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        sum[i + 1][j + 1] = sum[i + 1][j] + mat[i][j];
      }
    }
    for (int j = 0; j <= N; ++j) {
      for (int i = 0; i < M; ++i) {
        sum[i + 1][j] += sum[i][j];
      }
    }

    vector<vector<int>> result(M, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        int c1 = sum[min(i + K + 1, M)][min(j + K + 1, N)];
        int c2 = sum[min(i + K + 1, M)][max(j - K, 0)];
        int c3 = sum[max(i - K, 0)][min(j + K + 1, N)];
        int c4 = sum[max(i - K, 0)][max(j - K, 0)];
        result[i][j] = c1 - c2 - c3 + c4;
      }
    }
    return result;
  }
};