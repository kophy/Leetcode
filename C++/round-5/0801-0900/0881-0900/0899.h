class Solution {
public:
  string orderlyQueue(string S, int K) {
    // with K == 1, we can make all rotations of S.
    if (K == 1) {
      string result = S;
      for (int i = 1; i < S.size(); ++i) {
        string temp = S.substr(i) + S.substr(0, i);
        result = min(result, temp);
      }
      return result;
    }
    // with K > 1, we can make all permutations of S.
    else {
      sort(S.begin(), S.end());
      return S;
    }
  }
};
