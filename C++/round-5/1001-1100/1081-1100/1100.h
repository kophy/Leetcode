class Solution {
public:
  int numKLenSubstrNoRepeats(string S, int K) {
    int result = 0;
    unordered_map<char, int> count;
    for (int i = 0; i < S.size(); ++i) {
      ++count[S[i]];
      if (i >= K) {
        char c = S[i - K];
        if (--count[c] == 0) {
          count.erase(c);
        }
      }
      if (count.size() == K) {
        ++result;
      }
    }
    return result;
  }
};