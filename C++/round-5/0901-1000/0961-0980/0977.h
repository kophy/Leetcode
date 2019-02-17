class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    vector<int> result(A.size(), 0);
    transform(A.begin(), A.end(), result.begin(),
              [](int x) -> int { return x * x; });
    sort(result.begin(), result.end());
    return result;
  }
};
