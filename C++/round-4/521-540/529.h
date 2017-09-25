class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int>& click) {
        if (board.empty() || board[0].empty())
            return board;
        M = board.size();
        N = board[0].size();
        
        if (board[click[0]][click[1]] == 'M')
            board[click[0]][click[1]] = 'X';
        else
            revealEmptySquare(board, click[0], click[1]);
        return board;
    }
    
private:
    int M, N;
    
    bool isValidIndex(int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }
    
    void revealEmptySquare(vector<vector<char>> &board, int i, int j) {
        // only work on unrevealed empty square
        if (!isValidIndex(i, j) || board[i][j] != 'E')
            return;
        int mine_count = 0;
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                int ni = i + di, nj = j + dj;
                if (isValidIndex(ni, nj) && board[ni][nj] == 'M')
                    ++mine_count;
            }
        }
        if (mine_count == 0) {
            // search after update, avoid mutual dependency in recursion
            board[i][j] = 'B';
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    int ni = i + di, nj = j + dj;
                    if ((ni == i && nj == j) || !isValidIndex(ni, nj))
                        continue;
                    revealEmptySquare(board, ni, nj);
                }
            }
        } else
            board[i][j] = mine_count + '0';
    }
};