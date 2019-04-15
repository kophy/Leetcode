class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& A) {
    int result = 0;
    int max_first = A[0];  // max(A[i] + i)
    for (int j = 1; j < A.size(); ++j) {
      result = std::max(result, max_first + A[j] - j);
      max_first = std::max(max_first, A[j] + j);
    }
    return result;
  }
};
