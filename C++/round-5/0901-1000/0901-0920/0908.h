class Solution {
public:
  int smallestRangeI(vector<int> &A, int K) {
    int min_val = INT_MAX, max_val = INT_MIN;
    for (int i = 0; i < A.size(); ++i) {
      min_val = min(min_val, A[i]);
      max_val = max(max_val, A[i]);
    }
    int diff = max_val - min_val;
    return max(diff - 2 * K, 0);
  }
};
