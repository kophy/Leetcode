class Solution {
public:
    int countBattleships(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty())
            return 0;
        M = board.size();
        N = board[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        
        int result = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!visited[i][j] && board[i][j] == 'X') {
                    ++result;
                    grow(board, visited, i, j);
                }
            }
        }
        return result;
    }
    
private:
    int M, N;
    
    void grow(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j) {
        if (i < 0 || i >= M || j < 0 || j >= N || visited[i][j] || board[i][j] != 'X')
            return;
        visited[i][j] = true;
        int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
        for (int k = 0; k < 4; ++k)
            grow(board, visited, i + di[k], j + dj[k]);
    }
};