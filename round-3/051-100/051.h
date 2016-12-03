class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<vector<string>> result;
        vector<string> board(N, string(N, '.'));
        solve(result, board, 0);
        return result;
    }

private:
    int N;

    void solve(vector<vector<string>> &result, vector<string> &board, int row) {
        if (row == N) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < N; ++col) {
            if (!check(board, row, col))
                continue;
            board[row][col] = 'Q';
            solve(result, board, row + 1);
            board[row][col] = '.';
        }
    }

    bool check(vector<string> &board, int row, int col) {
        for (int i = 0; i < row; ++i)
            if (board[i][col] == 'Q')
                return false;
        for (int k = 1; row - k >= 0 && col - k >= 0; ++k)
            if (board[row - k][col - k] == 'Q')
                return false;
        for (int k = 1; row - k >= 0 && col + k < N; ++k)
            if (board[row - k][col + k] == 'Q')
                return false;
        return true;
    }
};