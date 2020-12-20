class Solution {
public:
  int minIncrementForUnique(vector<int> &A) {
    if (A.empty()) {
      return 0;
    }
    sort(A.begin(), A.end());
    int expected = A[0], result = 0;
    for (int x : A) {
      if (x >= expected) {
        expected = x + 1;
      } else {
        result += expected - x;
        ++expected;
      }
    }
    return result;
  }
};
