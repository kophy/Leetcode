class Solution {
 public:
  int minDeletionSize(vector<string> &A) {
    int N = A.size(), M = A[0].size();
    vector<int> dp(M, 1);
    for (int j = 1; j < M; ++j) {
      for (int k = 0; k < j; ++k) {
        if (isGreaterColumn(A, j, k)) {
          dp[j] = max(dp[j], dp[k] + 1);
        }
      }
    }
    return A[0].size() - *max_element(dp.begin(), dp.end());
  }

 private:
  bool isGreaterColumn(vector<string> &A, int j, int k) {
    for (int i = 0; i < A.size(); ++i) {
      if (A[i][j] < A[i][k]) {
        return false;
      }
    }
    return true;
  }
};
