class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*  maxify the profit of each check
        	if a number appears, then the row, the column and the box it belongs to
        	can not have same number.
        */
        bool used_r[9][9] = {false};
        bool used_c[9][9] = {false};
        bool used_g[9][9] = {false};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;

                /* calculate the element is in whcih 3 x 3 box */
                int k = (i / 3) * 3 + j / 3;

                int d = board[i][j] - '1';  // important: use '1' instead of '0'!
                if (used_r[i][d] || used_c[j][d] || used_g[k][d])
                    return false;
                used_r[i][d] = used_c[j][d] = used_g[k][d] = true;
            }
        }

        return true;
    }
};