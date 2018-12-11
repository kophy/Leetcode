class Solution {
 public:
  bool reorderedPowerOf2(int N) {
    vector<int> digits;
    while (N > 0) {
      digits.push_back(N % 10);
      N /= 10;
    }
    sort(digits.begin(), digits.end());
    while (true) {
      if (digits[0] != 0 && isPowerOf2(digits)) {
        return true;
      }
      if (!next_permutation(digits.begin(), digits.end())) {
        break;
      }
    }
    return false;
  }

 private:
  bool isPowerOf2(vector<int> &digits) {
    long num = 0;
    for (int digit : digits) {
      num = num * 10 + digit;
    }
    return (num & (num - 1)) == 0;
  }
};
