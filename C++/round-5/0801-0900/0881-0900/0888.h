class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    vector<int> result(2, -1);
    int sum_A = std::accumulate(A.begin(), A.end(), 0);
    int sum_B = std::accumulate(B.begin(), B.end(), 0);

    unordered_set<int> candies_B(B.begin(), B.end());
    for (int x : A) {
      int expected = (sum_B - sum_A) / 2 + x;
      if (candies_B.count(expected)) {
        result[0] = x;
        result[1] = expected;
      }
    }
    return result;
  }
};
