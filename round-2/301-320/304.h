class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        valid = !matrix.empty() && !matrix[0].empty();
        if (!valid)
            return;
        int M = matrix.size(), N = matrix[0].size();
        sum_table = vector<vector<int>>(M + 1, vector<int>(N + 1, 0));

        for (int i = 1; i <= M; ++i)
            for (int j = 1; j <= N; ++j)
                sum_table[i][j] = sum_table[i][j - 1] + matrix[i - 1][j - 1];
        for (int j = 1; j <= N; ++j)
            for (int i = 1; i <= M; ++i)
                sum_table[i][j] += sum_table[i - 1][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (!valid)
            return 0;
        return sum_table[row2 + 1][col2 + 1] - sum_table[row2 + 1][col1] - sum_table[row1][col2 + 1] + sum_table[row1][col1];
    }

private:
    vector<vector<int>> sum_table;
    bool valid;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);