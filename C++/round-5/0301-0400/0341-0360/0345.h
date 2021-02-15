class Solution {
 public:
  string reverseVowels(string s) {
    vector<int> vowel_index;
    for (int i = 0; i < s.size(); ++i) {
      if (isVowel(s[i])) {
        vowel_index.push_back(i);
      }
    }
    for (int i = 0; i < vowel_index.size() / 2; ++i) {
      swap(s[vowel_index[i]], s[vowel_index[vowel_index.size() - i - 1]]);
    }
    return s;
  }

 private:
  bool isVowel(char c) {
    static unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    return vowels.count(tolower(c));
  }
};