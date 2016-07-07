class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0)
            return;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int lives = numberOfLiveNeighbors(board, i, j);
                if (board[i][j] & 0x0001) {
                    if (lives < 2)
                        board[i][j] = 0x0001;
                    else if (lives <= 3)
                        board[i][j] = 0x0003;
                    else
                        board[i][j] = 0x0001;
                } else {
                    if (lives == 3)
                        board[i][j] = 0x0002;
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                board[i][j] >>= 1;
            }
        }
    }
private:
    int numberOfLiveNeighbors(vector<vector<int>>& board, int i, int j) {
        int count = 0;
        for (int x = max(i - 1, 0); x <= min(i + 1, (int)board.size() - 1); ++x) {
            for (int y = max(j - 1, 0); y <= min(j + 1, (int)board[0].size() - 1); ++y) {
                if ((board[x][y] & 0x0001) && ((x != i) || (y != j)))
                    ++count;
            }
        }
        return count;
    }
};