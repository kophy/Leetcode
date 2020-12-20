class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    unordered_map<string, int> count;
    for (const auto &d : dominoes) {
      stringstream ss;
      ss << std::min(d[0], d[1]) << ":" << std::max(d[0], d[1]);
      ++count[ss.str()];
    }
    int result = 0;
    for (const auto &p : count) {
      result += p.second * (p.second - 1) / 2;
    }
    return result;
  }
};
