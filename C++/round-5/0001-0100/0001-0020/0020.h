class Solution {
public:
  bool isValid(string s) {
    stack<char> unclosed;
    unordered_map<char, char> m = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    for (char c : s) {
      if (m.count(c)) {
        unclosed.push(c);
      } else {
        if (unclosed.empty() || m[unclosed.top()] != c) {
          return false;
        }
        unclosed.pop();
      }
    }
    return unclosed.empty();
  }
};
