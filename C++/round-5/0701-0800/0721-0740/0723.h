class Solution {
public:
  vector<vector<int>> candyCrush(vector<vector<int>> &board) {
    if (board.empty() || board[0].empty()) {
      return board;
    }
    M = board.size();
    N = board[0].size();

    while (true) {
      auto crashed_candies = getCrashedCandies(board);
      if (crashed_candies.empty()) {
        break;
      }
      for (auto &c : crashed_candies) {
        board[c[0]][c[1]] = 0;
      }
      dropCandies(board);
    }
    return board;
  }

private:
  int M, N;

  vector<vector<int>> getCrashedCandies(vector<vector<int>> &board) {
    vector<vector<int>> crashed_candies;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (board[i][j] == 0) {
          continue;
        }
        if (isCrashableRow(board, i, j)) {
          for (int k = -1; k <= 1; ++k) {
            crashed_candies.push_back({i, j + k});
          }
        }
        if (isCrashableColumn(board, i, j)) {
          for (int k = -1; k <= 1; ++k) {
            crashed_candies.push_back({i + k, j});
          }
        }
      }
    }
    return crashed_candies;
  }

  void dropCandies(vector<vector<int>> &board) {
    for (int j = 0; j < N; ++j) {
      int k = M - 1;
      for (int i = M - 1; i >= 0; --i) {
        if (board[i][j] != 0) {
          board[k][j] = board[i][j];
          --k;
        }
      }
      for (; k >= 0; --k) {
        board[k][j] = 0;
      }
    }
  }

  bool isCrashableRow(vector<vector<int>> &board, int i, int j) {
    for (int k = -1; k <= 1; ++k) {
      if (j + k < 0 || j + k >= N || board[i][j + k] != board[i][j]) {
        return false;
      }
    }
    return true;
  }

  bool isCrashableColumn(vector<vector<int>> &board, int i, int j) {
    for (int k = -1; k <= 1; ++k) {
      if (i + k < 0 || i + k >= M || board[i + k][j] != board[i][j]) {
        return false;
      }
    }
    return true;
  }
};
