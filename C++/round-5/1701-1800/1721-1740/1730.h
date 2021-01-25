class Solution {
 public:
  int getFood(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    M = grid.size();
    N = grid[0].size();

    queue<tuple<int, int, int>> data;
    unordered_set<int> seen;
    for (int i = 0; i < M && data.empty(); ++i) {
      for (int j = 0; j < N && data.empty(); ++j) {
        if (grid[i][j] == '*') {
          data.push(make_tuple(i, j, 0));
          seen.insert(encode(i, j));
        }
      }
    }

    while (!data.empty()) {
      auto [i, j, step] = data.front();
      data.pop();

      int di[4] = {-1, 0, 1, 0};
      int dj[4] = {0, -1, 0, 1};
      for (int k = 0; k < 4; ++k) {
        int ni = i + di[k], nj = j + dj[k];
        int id = encode(ni, nj);
        if (!isValid(ni, nj) || seen.count(id)) {
          continue;
        }
        seen.insert(encode(ni, nj));
        if (grid[ni][nj] == 'X') {
          continue;
        }
        if (grid[ni][nj] == '#') {
          return step + 1;
        }
        if (grid[ni][nj] == 'O') {
          data.push(make_tuple(ni, nj, step + 1));
        }
      }
    }
    return -1;
  }

 private:
  int M, N;

  bool isValid(int i, int j) { return i >= 0 && j >= 0 && i < M && j < N; }

  int encode(int i, int j) { return i * N + j; }
};