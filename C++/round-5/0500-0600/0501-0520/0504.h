class Solution {
 public:
  string convertToBase7(int num) {
    int flag = (num >= 0) ? 1 : -1;
    long lnum = abs(long(num));
    vector<char> digits;
    while (true) {
      digits.push_back('0' + lnum % 7);
      lnum /= 7;
      if (lnum == 0) {
        break;
      }
    }
    if (flag == -1) {
      digits.push_back('-');
    }
    return string(digits.rbegin(), digits.rend());
  }
};
