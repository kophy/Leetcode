class Solution {
public:
    int countBattleships(vector<vector<char>> &board) {
        if (board.size() == 0 || board[0].size() == 0)
            return 0;
        M = board.size();
        N = board[0].size();
        int count = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] != 'X')
                    continue;
                ++count;
                growBattleShip(board, i, j);
            }
        }
        return count;
    }

private:
    int M, N;

    bool isValidIndex(int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }

    void growBattleShip(vector<vector<char>> &board, int i, int j) {
        if (isValidIndex(i, j) && board[i][j] == 'X') {
            board[i][j] = '@';
            growBattleShip(board, i + 1, j);
            growBattleShip(board, i - 1, j);
            growBattleShip(board, i, j + 1);
            growBattleShip(board, i, j - 1);
        }
    }
};