class Solution {
 public:
  int countPairs(vector<int>& deliciousness) {
    unordered_map<int, int> count;
    for (int& d : deliciousness) {
      ++count[d];
    }
    int M = pow(10, 9) + 7;
    long result = 0;
    unordered_set<int> seen;
    for (auto& a : count) {
      for (int i = 0; i <= 21; i++) {
        int b = pow(2, i) - a.first;
        if (seen.count(b)) {
          result += a.second * count[b];
        } else if (b == a.first) {
          result += (long)(a.second - 1) * a.second / 2;
        }
      }
      seen.insert(a.first);
      result %= M;
    }
    return result;
  }
};