class Solution {
 public:
  int distinctEchoSubstrings(string text) {
    unordered_set<string> result;
    for (int i = 0; i < text.size(); ++i) {
      for (int len = 1; i + len * 2 <= text.size(); ++len) {
        string_view left(text.c_str() + i, len);
        string_view right(text.c_str() + i + len, len);
        if (left == right) {
          result.insert(string(left));
        }
      }
    }
    return result.size();
  }
};