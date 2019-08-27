class Solution {
 public:
  string removeVowels(string S) {
    int j = 0;
    for (int i = 0; i < S.size(); ++i) {
      if (!isVowel(S[i])) {
        S[j++] = S[i];
      }
    }
    S.resize(j);
    return S;
  }

 private:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
