class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }

private:
    /*  crack vacant numbers one by one
    	for each vacant number, give it a value and try to crack next until failure detected.
    */
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9)	// completed
            return true;
        if (j == 9)	// crack next number
            return solve(board, i + 1, 0);
        if (board[i][j] != '.')
            return solve(board, i, j + 1);

        for (char c = '1'; c <= '9'; ++c) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solve(board, i, j + 1))	// crack next number
                    return true;
                board[i][j] = '.';
            }
        }
        return false;	// failure, numbers before are assigned with wrong value
    }

    bool check(vector<vector<char>>& board, int i, int j, char val) {
        for (int x = 0; x < 9; ++x)
            if (board[x][j] == val)
                return false;
        for (int y = 0; y < 9; ++y)
            if (board[i][y] == val)
                return false;
        int bx = i - i % 3, by = j - j % 3;
        for (int x = bx; x < bx + 3; ++x)
            for (int y = by; y < by + 3; ++y)
                if (board[x][y] == val)
                    return false;
        return true;
    }
};