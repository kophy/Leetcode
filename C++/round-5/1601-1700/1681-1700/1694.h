class Solution {
 public:
  string reformatNumber(string number) {
    string digits;
    for (const char c : number) {
      if (isdigit(c)) {
        digits.push_back(c);
      }
    }
    stringstream ss;
    int i = 0, len = digits.size();
    while (i < len) {
      if (i + 4 < len) {
        ss << digits.substr(i, 3) << "-";
        i += 3;
      } else if (i + 4 == len) {
        ss << digits.substr(i, 2) << "-" << digits.substr(i + 2, 2);
        i += 4;
      } else if (i + 3 == len) {
        ss << digits.substr(i, i + 3);
        i += 3;
      } else if (i + 2 == len) {
        ss << digits.substr(i, i + 2);
        i += 2;
      }
    }
    return ss.str();
  }
};