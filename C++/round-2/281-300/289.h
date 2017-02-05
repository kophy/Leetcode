class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        if (board.empty() || board[0].empty())
            return;
        M = board.size(), N = board[0].size();

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int n = calculate_neighbors(board, i, j);
                if ((board[i][j] & 1) && n < 2)
                    board[i][j] &= ~2;
                else if ((board[i][j] & 1) && n <= 3)
                    board[i][j] |= 2;
                else if ((board[i][j] & 1) && n > 3)
                    board[i][j] &= ~2;
                else if (!(board[i][j] & 1) && n == 3)
                    board[i][j] |= 2;
            }
        }

        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                board[i][j] >>= 1;
    }

private:
    int M, N;
    int calculate_neighbors(vector<vector<int>> &board, int i, int j) {
        int count = 0;
        for (int di = -1; di <= 1; ++di)
            for (int dj = -1; dj <= 1; ++dj)
                if (valid(i + di, j + dj) && (di || dj))
                    count += (board[i + di][j + dj] & 1)? 1 : 0;
        return count;
    }

    bool valid (int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }
};