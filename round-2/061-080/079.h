class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (search(board, word, 0, i, j))
                    return true;
        return false;
    }
private:
    bool search(vector<vector<char>> &board, string &word, int pos, int i, int j) {
        if (board[i][j] != word[pos])
            return false;
        ++pos;

        /* the whole word is found */
        if (pos == word.size())
            return true;

        char c = board[i][j];
        board[i][j] = '@';		// mark the element as visited

        /*  dfs
            search 4 directions if correscorresponding adjacent element exists */
        if (i + 1 < board.size() && search(board, word, pos, i + 1, j))
            return true;
        if (i - 1 >= 0 && search(board, word, pos, i - 1, j))
            return true;
        if (j + 1 < board[0].size() && search(board, word, pos, i, j + 1))
            return true;
        if (j - 1 >= 0 && search(board, word, pos, i, j - 1))
            return true;

        board[i][j] = c;        // cancel the mark
        return false;
    }
};