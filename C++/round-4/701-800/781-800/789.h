class Solution {
 public:
  bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
    // the best strategy for ghost is to go directly to the target
    int d = manhattan_distance(vector<int>(2, 0), target);
    for (auto &ghost : ghosts) {
      if (manhattan_distance(ghost, target) <= d) return false;
    }
    return true;
  }

 private:
  int manhattan_distance(const vector<int> &s, const vector<int> &t) {
    return abs(s[0] - t[0]) + abs(s[1] - t[1]);
  }
};
