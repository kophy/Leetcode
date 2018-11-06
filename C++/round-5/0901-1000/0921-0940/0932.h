class Solution {
 public:
  vector<int> beautifulArray(int N) {
    if (memo.count(N)) {
      return memo[N];
    }
    vector<int> result(N, 0);
    if (N == 1) {
      result[0] = 1;
    } else {
      vector<int> left = beautifulArray(N / 2);
      vector<int> right = beautifulArray((N + 1) / 2);
      int i = 0;
      for (int val : left) {
        result[i++] = 2 * val;
      }
      for (int val : right) {
        result[i++] = 2 * val - 1;
      }
    }
    memo[N] = result;
    return result;
  }

 private:
  unordered_map<int, vector<int>> memo;
};
