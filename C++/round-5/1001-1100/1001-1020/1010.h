class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    unordered_map<int, int> m;
    for (int t : time) {
      ++m[t % 60];
    }
    int result = 0;
    for (const auto &p : m) {
      if (p.first == 0 || p.first == 30) {
        result += p.second * (p.second - 1);
      } else if (m.count(60 - p.first)) {
        result += p.second * m[60 - p.first];
      }
    }
    return result / 2;
  }
};
