class Solution {
 public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    unordered_map<string, int> substr_count;
    unordered_map<char, int> unique_characters;

    for (int i = 0; i < s.size(); ++i) {
      unique_characters[s[i]]++;
      // Keep only substrings of length minSize.
      // If a longer string has the max count, its substring of length minSize
      // must also has the max count.
      if (i >= minSize) {
        --unique_characters[s[i - minSize]];
        if (unique_characters[s[i - minSize]] == 0) {
          unique_characters.erase(s[i - minSize]);
        }
      }

      if (i >= minSize - 1) {
        if (unique_characters.size() <= maxLetters) {
          ++substr_count[s.substr(i - minSize + 1, minSize)];
        }
      }
    }

    int max_count = 0;
    for (const auto& iter : substr_count) {
      if (iter.second > max_count) {
        max_count = iter.second;
      }
    }
    return max_count;
  }
};