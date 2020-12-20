class Solution {
public:
  int numRookCaptures(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == 'R') {
          return numRookCaptures(board, i, j, 0, 1) +
                 numRookCaptures(board, i, j, 0, -1) +
                 numRookCaptures(board, i, j, 1, 0) +
                 numRookCaptures(board, i, j, -1, 0);
        }
      }
    }
    return 0;
  }

private:
  int numRookCaptures(const vector<vector<char>> &board, int i, int j, int di,
                      int dj) {
    while (true) {
      i += di;
      j += dj;
      if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
        return 0;
      }
      if (board[i][j] == 'B') {
        return 0;
      }
      if (board[i][j] == 'p') {
        return 1;
      }
    }
    return 0;
  }
};
