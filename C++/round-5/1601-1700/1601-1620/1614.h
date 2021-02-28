class Solution {
 public:
  int maxDepth(string s) {
    int max_depth = 0, depth = 0;
    for (char c : s) {
      if (c == '(') {
        max_depth = max(max_depth, ++depth);
      } else if (c == ')') {
        --depth;
      }
    }
    return max_depth;
  }
};