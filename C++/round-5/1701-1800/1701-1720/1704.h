class Solution {
 public:
  bool halvesAreAlike(string s) {
    int len = s.size();
    return countVowels(s, 0, len / 2) == countVowels(s, len / 2, len);
  }

 private:
  unordered_set<char> vowels_ = {'a', 'e', 'i', 'o', 'u'};

  int countVowels(const string& s, int begin, int end) {
    int count = 0;
    for (int i = begin; i < end; ++i) {
      if (!vowels_.count(tolower(s[i]))) {
        continue;
      }
      ++count;
    }
    return count;
  }
};