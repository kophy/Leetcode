class Solution {
 public:
  int sumSubseqWidths(vector<int> &A) {
    int N = A.size(), M = 1e9 + 7;
    long coeff = 1, result = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); ++i) {
      result = (result + A[i] * coeff - A[N - i - 1] * coeff) % M;
      coeff = (coeff << 1) % M;
    }
    return (result + M) % M;
  }
};
