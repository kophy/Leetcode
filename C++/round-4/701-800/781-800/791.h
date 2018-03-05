class Solution {
 public:
  string customSortString(string S, string T) {
    unordered_map<char, int> m;
    for (int i = 0; i < S.size(); ++i) {
      if (!m.count(S[i])) m[S[i]] = i;
    }
    // handle characters not in S
    int v = S.size();
    for (char c = 'a'; c <= 'z'; ++c) {
      if (!m.count(c)) m[c] = v++;
    }
    sort(T.begin(), T.end(),
         [&m](char a, char b) -> bool { return m[a] < m[b]; });
    return T;
  }
};
