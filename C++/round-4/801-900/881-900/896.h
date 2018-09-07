class Solution {
 public:
  bool isMonotonic(vector<int>& A) {
    if (A.size() <= 2) return true;

    // find first pair A[i - 1] and A[i] that are not equal.
    int i = 0;
    while (i < A.size() && A[i] == A[0]) {
      ++i;
    }
    // all elements in the array are equal.
    if (i == A.size()) return true;

    // check all following elements have same monotony as A[i - 1] and A[i].
    bool increasing = (A[i - 1] < A[i]);
    for (; i < A.size() - 1; ++i) {
      if ((increasing && (A[i] > A[i + 1])) ||
          (!increasing && (A[i] < A[i + 1]))) {
        return false;
      }
    }
    return true;
  }
};
