class Solution {
 public:
  int minimumDistance(string word) {
    unordered_map<string, int> dp;
    dp["##"] = 0;

    for (char target : word) {
      unordered_map<string, int> temp;
      for (const auto &p : dp) {
        char c1 = p.first[0], c2 = p.first[1];
        string new_pos1 = string({target, c2}), new_pos2 = string({c1, target});
        if (!temp.count(new_pos1)) {
          temp[new_pos1] = INT_MAX;
        }
        if (!temp.count(new_pos2)) {
          temp[new_pos2] = INT_MAX;
        }

        temp[new_pos1] =
            std::min(temp[new_pos1], p.second + distance(c1, target));
        temp[new_pos2] =
            std::min(temp[new_pos2], p.second + distance(c2, target));
      }
      dp = std::move(temp);
    }

    int result = INT_MAX;
    for (const auto &p : dp) {
      result = std::min(result, p.second);
    }
    return result;
  }

 private:
  int distance(char c1, char c2) {
    if (c1 == '#' || c2 == '#') {
      return 0;
    }
    int i1 = c1 - 'A', i2 = c2 - 'A';
    return abs(i1 / 6 - i2 / 6) + abs(i1 % 6 - i2 % 6);
  }
};