class Solution {
 public:
  bool isSubsequence(string s, string t) { return isSubsequence(s, 0, t, 0); }

 private:
  bool isSubsequence(const string &s, int i, const string &t, int j) {
    if (i == s.size()) {
      return true;
    }
    if (j == t.size()) {
      return false;
    }
    if (s[i] == t[j]) {
      return isSubsequence(s, i + 1, t, j + 1);
    } else {
      return isSubsequence(s, i, t, j + 1);
    }
  }
};