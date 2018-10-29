class Solution {
 public:
  int smallestRangeII(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int N = A.size();
    int result = A[N - 1] - A[0];
    for (int i = 0; i < N - 1; ++i) {
      // increase elements in A[0:i] by K. decrease elements in A[i+1:N-1] by K.
      // calculate new maximum and minimum values.
      int max_val = max(A[i] + K, A[N - 1] - K);
      int min_val = min(A[i + 1] - K, A[0] + K);
      result = min(result, max_val - min_val);
    }
    return result;
  }
};
