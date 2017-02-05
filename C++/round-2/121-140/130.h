class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;
        int M = board.size(), N = board[0].size();
        for (int i = 0; i < M; ++i) {
            grow(board, i, 0);
            if (N > 1)
                grow(board, i, N - 1);
        }
        for (int j = 0; j < N; ++j) {
            grow(board, 0, j);
            if (M > 1)
                grow(board, M - 1, j);
        }

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '@')
                    board[i][j] = 'O';
            }
        }
    }

private:
    void grow(vector<vector<char>> &board, int i, int j) {
        if (board[i][j] != 'O')
            return;
        board[i][j] = '@';
        cout << i << " " << j << endl;
        if (i - 1 > 0)
            grow(board, i - 1, j);
        if (i + 1 < board.size())
            grow(board, i + 1, j);
        if (j - 1 > 0)
            grow(board, i, j - 1);
        if (j + 1 < board[0].size())
            grow(board, i, j + 1);
    }
};