class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used_r[9][9] = {false};
        bool used_c[9][9] = {false};
        bool used_g[9][9] = {false};

        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int k = i / 3 * 3 + j / 3;
                    if(used_r[i][num - 1] || used_c[j][num - 1] || used_g[k][num - 1])
                        return false;
                    used_r[i][num - 1] = used_c[j][num - 1] = used_g[k][num - 1] = true;
                }
            }
        }
        return true;
    }
};