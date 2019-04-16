class Solution {
 public:
  string baseNeg2(int N) {
    string result;
    while (N) {
      // N = d * (-2) + carry
      // d is the smallest number keeps carry positive.
      int d = N / (-2);
      if (d * (-2) > N) {
        ++d;
      }
      result.push_back('0' + N + (d * 2));
      N = d;
    }
    reverse(result.begin(), result.end());
    return result.empty() ? "0" : result;
  }
};
