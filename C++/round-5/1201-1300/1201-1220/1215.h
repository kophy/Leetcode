class Solution {
 public:
  vector<int> countSteppingNumbers(int low, int high) {
    vector<int> result;
    if (low == 0) {
      result.push_back(0);
    }
    for (int i = 1; i < 10; ++i) {
      helper(i, low, high, result);
    }
    sort(result.begin(), result.end());
    return result;
  }

 private:
  void helper(long curr, int low, int high, vector<int> &result) {
    if (curr > high) {
      return;
    }
    if (curr >= low) {
      result.push_back(curr);
    }
    int last_digit = curr % 10;
    if (last_digit != 0) {
      helper(curr * 10 + last_digit - 1, low, high, result);
    }
    if (last_digit != 9) {
      helper(curr * 10 + last_digit + 1, low, high, result);
    }
  }
};