// bipartition <=> paint nodes with two colors
class Solution {
public:
  bool possibleBipartition(int N, vector<vector<int>> &dislikes) {
    unordered_map<int, vector<int>> dislike_map;
    for (const auto &p : dislikes) {
      dislike_map[p[0]].push_back(p[1]);
      dislike_map[p[1]].push_back(p[0]);
    }
    unordered_map<int, int> colors;
    for (int i = 0; i < N; ++i) {
      if (!colors.count(i)) {
        if (!paint(colors, dislike_map, i, 0)) {
          return false;
        }
      }
    }
    return true;
  }

private:
  bool paint(unordered_map<int, int> &colors,
             unordered_map<int, vector<int>> &dislike, int i, int color) {
    if (colors.count(i)) {
      return colors[i] == color;
    }
    colors[i] = color;
    for (auto j : dislike[i]) {
      if (!paint(colors, dislike, j, 1 - color)) {
        return false;
      }
    }
    return true;
  }
};
