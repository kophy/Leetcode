class Solution {
public:
  bool validMountainArray(vector<int> &A) {
    if (A.size() < 3) {
      return false;
    }
    int i = 0;
    while (i < A.size() - 1 && A[i] < A[i + 1]) {
      ++i;
    }
    if (i == 0 || i == A.size() - 1) {
      return false;
    }
    while (i < A.size() - 1 && A[i] > A[i + 1]) {
      ++i;
    }
    return i == A.size() - 1;
  }
};
