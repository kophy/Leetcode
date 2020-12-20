class Solution {
public:
  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i <= n / 2; ++i) {
      if (!hasZero(i) && !hasZero(n - i)) {
        return {i, n - i};
      }
    }
    return {0, 0};
  }

private:
  bool hasZero(int n) {
    while (n > 0) {
      if (n % 10 == 0) {
        return true;
      }
      n /= 10;
    }
    return false;
  }
};