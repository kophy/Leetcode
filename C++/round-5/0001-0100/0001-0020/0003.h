/* Method 1: count */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int max_length = 0;
    vector<int> count(256, 0);
    // sliding window of valid substring s[i:j]
    for (int i = 0, j = 0; j < s.size(); ++j) {
      ++count[s[j]];
      while (i < j && count[s[j]] > 1) {
        --count[s[i]];
        ++i;
      }
      max_length = max(max_length, j - i + 1);
    }
    return max_length;
  }
};

/* Method 2: index of last appearance */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int max_length = 0;
    unordered_map<char, int> char2idx;
    // sliding window of valid substring s[i:j)
    for (int i = 0, j = 0; j <= s.size(); ++j) {
      char c = s[j];
      if (j == s.size() || (char2idx.count(c) && char2idx[c] >= i)) {
        max_length = max(max_length, j - i);
        i = char2idx[c] + 1;
      }
      char2idx[c] = j;
    }
    return max_length;
  }
};
