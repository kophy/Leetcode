class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> current(n, string(n, '.'));
        if (n > 0)
            solve(result, n, 0, current);
        return result;
    }

private:
    void solve(vector<vector<string>> &result, int n, int row, vector<string> &current) {
        if (row == n) {
            result.push_back(current);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isValid(current, n, row, col)) {
                current[row][col] = 'Q';
                solve(result, n, row + 1, current);
                current[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string> &current, int n, int row, int col) {
        /* check whether another queen exists in this row */
        for (int i = 0; i < row; ++i)
            if (current[i][col] == 'Q')
                return false;

        /* check positive 45 degree diagonal */
        for (int k = 1; row - k >= 0 && col + k < n; ++k)
            if (current[row - k][col + k] == 'Q')
                return false;

        /* check negative 45 degree diagonal */
        for (int k = 1; row - k >= 0 && col - k >= 0; ++k)
            if (current[row - k][col - k] == 'Q')
                return false;

        return true;
    }
};