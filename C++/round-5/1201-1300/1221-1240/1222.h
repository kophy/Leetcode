class Solution {
public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens,
                                          vector<int> &king) {
    unordered_map<int, vector<int>> m;
    for (const auto &q : queens) {
      m[getIndex(q[0], q[1])] = q;
    }
    vector<vector<int>> result;
    // All possible directions.
    int directions[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (int k = 0; k < 8; ++k) {
      int i = king[0], j = king[1];
      while (true) {
        i += directions[k][0];
        j += directions[k][1];
        if (!isValidCoordinate(i, j)) {
          break;
        }
        auto iter = m.find(getIndex(i, j));
        if (iter != m.end()) {
          // Return early since others queens in that direction are blocked.
          result.push_back(iter->second);
          break;
        }
      }
    }
    return result;
  }

private:
  int getIndex(int i, int j) { return (i << 3) + j; }

  bool isValidCoordinate(int i, int j) {
    return i >= 0 && i < 8 && j >= 0 && j < 8;
  }
};