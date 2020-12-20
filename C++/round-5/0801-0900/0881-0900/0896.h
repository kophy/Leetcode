class Solution {
public:
  bool isMonotonic(vector<int> &A) {
    int i = 0;
    // skip all equal elements.
    while (i + 1 < A.size() && A[i] == A[i + 1]) {
      ++i;
    }
    if (i == A.size()) {
      return true;
    }
    bool increasing = A[i] < A[i + 1];
    while (i + 1 < A.size()) {
      if (increasing) {
        if (A[i] > A[i + 1]) {
          return false;
        }
      } else {
        if (A[i] < A[i + 1]) {
          return false;
        }
      }
      ++i;
    }
    return true;
  }
};
