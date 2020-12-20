class Solution {
public:
  int balancedStringSplit(string s) {
    int count = 0;
    int diff = 0;
    for (char c : s) {
      diff += (c == 'L' ? 1 : -1);
      if (diff == 0) {
        ++count;
      }
    }
    return count;
  }
};