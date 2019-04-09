class Solution {
 public:
  bool canThreePartsEqualSum(vector<int> &A) {
    int N = A.size();
    if (N < 3) {
      return false;
    }
    vector<int> presum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
      presum[i + 1] = presum[i] + A[i];
    }
    if (presum[N] % 3 != 0) {
      return 0;
    }
    int partition = presum[N] / 3;
    for (int i = 0; i < N; ++i) {
      if (presum[i] != partition) {
        continue;
      }
      for (int j = i + 1; j <= N; ++j) {
        if (presum[j] - presum[i] == partition) {
          return true;
        }
      }
    }
    return false;
  }
};
