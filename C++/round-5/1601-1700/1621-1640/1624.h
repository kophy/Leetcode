class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    unordered_map<char, int> first_index;
    int result = -1;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (!first_index.count(c)) {
        first_index[c] = i;
      } else {
        result = max(result, i - first_index[c] - 1);
      }
    }
    return result;
  }
};