class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> result;
    for (int i = 1; i <= 9; ++i) {
      backtracking(result, low, high, i);
    }
    sort(result.begin(), result.end());
    return result;
  }

private:
  void backtracking(vector<int> &result, int low, int high, int current) {
    if (current > high) {
      return;
    }
    if (current >= low && current <= high) {
      result.push_back(current);
    }

    int last_digit = current % 10;
    if (last_digit < 9) {
      backtracking(result, low, high, current * 10 + last_digit + 1);
    }
  }
};