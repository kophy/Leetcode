class Solution {
public:
  int minAddToMakeValid(string S) {
    int result = 0;
    int unclosed = 0;
    for (char c : S) {
      if (c == '(') {
        ++unclosed;
      } else {
        if (unclosed > 0) {
          --unclosed;
        } else {
          // insert '(' before this ')'
          ++result;
        }
      }
    }
    // insert ')' in the end of string
    result += unclosed;
    return result;
  }
};
