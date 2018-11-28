class Solution {
 public:
  int minDeletionSize(vector<string>& A) {
    if (A.empty()) {
      return 0;
    }
    int result = 0;
    for (int c = 0; c < A[0].size(); ++c) {
      for (int i = 0; i < (int)A.size() - 1; ++i) {
        if (A[i][c] > A[i + 1][c]) {
          ++result;
          break;
        }
      }
    }
    return result;
  }
};
