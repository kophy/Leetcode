class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int result = 0;
    unordered_map<char, int> window;
    int begin = 0;
    for (int i = 0; i < s.size(); ++i) {
      ++window[s[i]];
      while (begin <= i && window.size() > k) {
        char c = s[begin];
        if (--window[c] == 0) {
          window.erase(c);
        }
        ++begin;
      }
      result = max(result, i - begin + 1);
    }
    return result;
  }
};