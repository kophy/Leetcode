class Solution {
public:
  string freqAlphabets(string s) {
    string result;
    int i = 0;
    while (i < s.size()) {
      if (i + 1 >= s.size()) {
        result.push_back('a' + s[i] - '1');
        ++i;
      } else {
        if (i + 2 < s.size() && s[i + 2] == '#') {
          result.push_back('a' + (s[i] - '0') * 10 + (s[i + 1] - '1'));
          i += 3;
        } else {
          result.push_back('a' + s[i] - '1');
          ++i;
        }
      }
    }
    return result;
  }
};