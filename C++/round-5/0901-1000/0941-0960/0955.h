class Solution {
public:
  int minDeletionSize(vector<string> &A) {
    int N = A[0].size();
    int deletion = 0;
    vector<bool> sorted((int)A.size() - 1, false);
    for (int j = 0; j < N; ++j) {
      if (keepSorted(A, sorted, j)) {
        for (int i = 0; i < (int)A.size() - 1; ++i) {
          if (A[i][j] < A[i + 1][j]) {
            sorted[i] = true;
          }
        }
      } else {
        ++deletion;
      }
    }
    return deletion;
  }

private:
  bool keepSorted(vector<string> &A, vector<bool> &sorted, int j) {
    for (int i = 0; i < (int)A.size() - 1; ++i) {
      if (!sorted[i] && (A[i][j] > A[i + 1][j])) {
        return false;
      }
    }
    return true;
  }
};
