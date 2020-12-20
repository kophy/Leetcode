class Solution {
public:
  string removeOuterParentheses(string S) {
    stringstream ss;
    int count = 0;
    for (int i = 0, j = 0; j < S.size(); ++j) {
      if (S[j] == '(') {
        ++count;
      } else {
        --count;
        if (count == 0) {
          ss << S.substr(i + 1, j - i - 1);
          i = j + 1;
        }
      }
    }
    return ss.str();
  }
};
