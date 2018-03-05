class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0)
            return false;
        M = board.size();
        N = board[0].size();
        
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                if (dfs(board, word, 0, i, j))
                    return true;
        return false;
    }
    
private:
    int M, N;
    
    bool dfs(vector<vector<char>>& board, string& word, int pos, int i, int j) {
        if (pos == word.size())
            return true;
        if (!isValidIndex(i, j) || board[i][j] != word[pos])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '@';
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for (int k = 0; k < 4; ++k) {
            if (dfs(board, word, pos + 1, i + dx[k], j + dy[k])) {
                board[i][j] = temp;
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    
    bool isValidIndex(int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }
};