class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (search(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
private:
    bool search(vector<vector<char>> &board, string &word, int index, int i, int j) {
        if (board[i][j] != word[index])
            return false;
        ++index;
        if (index == word.size())
            return true;
        char c = board[i][j];
        board[i][j] = '@';
        if (i + 1 < board.size() && search(board, word, index, i + 1, j))
            return true;
        if (i - 1 >= 0 && search(board, word, index, i - 1, j))
            return true;
        if (j + 1 < board[0].size() && search(board, word, index, i, j + 1))
            return true;
        if (j - 1 >= 0 && search(board, word, index, i, j - 1))
            return true;
        board[i][j] = c;
        return false;
    }
};