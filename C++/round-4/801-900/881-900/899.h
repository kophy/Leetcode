class Solution {
 public:
  string orderlyQueue(string S, int K) {
    string result = S;
    if (K == 1) {
      // when K = 1, possible results are rotations of S.
      for (int len = 1; len < S.size(); ++len) {
        result = min(result, S.substr(len) + S.substr(0, len));
      }
    } else {
      // when K > 1, possible results are permutations of S.
      sort(result.begin(), result.end());
    }
    return result;
  }
};
