class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    unordered_map<int, int> count = {{5, 0}, {10, 0}, {20, 0}};
    for (int bill : bills)
      if (!buy(count, bill)) return false;
    return true;
  }

 private:
  bool buy(unordered_map<int, int>& count, int bill) {
    int change = bill - 5;
    for (int m : {20, 10, 5}) {
      while (change >= m && count[m] > 0) {
        change -= m;
        --count[m];
      }
    }
    if (change == 0) {
      ++count[bill];
      return true;
    }
    return false;
  }
};
