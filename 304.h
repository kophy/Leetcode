class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int col = 0;
        if (row > 0)
            col = matrix[0].size();
        for (int i = 0; i < row + 1; ++i)
            sum.push_back(vector<int>(col + 1, 0));
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j) {
                sum[i+1][j+1] = matrix[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
            }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }
private:
    vector<vector<int>> sum;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);