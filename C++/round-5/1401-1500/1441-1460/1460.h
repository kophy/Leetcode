class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> count;
    for (int x : target) {
      ++count[x];
    }
    for (int x : arr) {
      if (!count.count(x)) {
        return false;
      }
      if (--count[x] == 0) {
        count.erase(x);
      }
    }
    return true;
  }
};