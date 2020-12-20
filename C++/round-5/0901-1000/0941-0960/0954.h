class Solution {
public:
  bool canReorderDoubled(vector<int> &A) {
    auto cmp = [](int a, int b) -> bool { return abs(a) < abs(b); };
    map<int, int, decltype(cmp)> count(cmp);
    for (int a : A) {
      ++count[a];
    }
    while (!count.empty()) {
      int a = count.begin()->first;
      if (a == 0 && count[a] % 2 != 0) {
        return false;
      } else {
        if (!count.count(2 * a) || count[2 * a] < count[a]) {
          return false;
        }
        count[2 * a] -= count[a];
        count.erase(a);
        if (count[2 * a] == 0) {
          count.erase(2 * a);
        }
      }
    }
    return true;
  }
};
