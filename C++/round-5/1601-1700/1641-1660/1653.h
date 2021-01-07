class Solution {
 public:
  int minimumDeletions(string s) {
    unordered_map<int, int> a_suffix_count;
    int count = 0;
    for (int i = (int)s.size() - 1; i >= 0; --i) {
      a_suffix_count[i] = count;
      if (s[i] == 'a') {
        ++count;
      }
    }
    int result = (int)s.size() - 1;
    count = 0;
    for (int i = 0; i < s.size(); ++i) {
      result = min(result, count + a_suffix_count[i]);
      if (s[i] == 'b') {
        ++count;
      }
    }
    return result;
  }
};