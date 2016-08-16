class Solution {
public:
    void solve(vector<vector<char>> &board) {
        row = board.size();
        if(row == 0)
            return;
        col = board[0].size();

        for(int i = 0; i < row; ++i) {
            check(board, i, 0);
            if(col > 1)
                check(board, i, col - 1);
        }
        for(int j = 1; j + 1 < col; ++j) {
            check(board, 0, j);
            if(row > 1)
                check(board, row - 1, j);
        }
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
    void check(vector<vector<char>> &board, int i, int j) {
        if(board[i][j] == 'O') {
            board[i][j] = '1';
            if(i > 1)
                check(board, i - 1, j);
            if(j > 1)
                check(board, i, j - 1);
            if(i + 1 < row)
                check(board, i + 1, j);
            if(j + 1 < col)
                check(board, i, j + 1);
        }
    }

private:
    int row, col;
};