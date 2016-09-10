class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(2, vector<int>(rowIndex + 1));

        for (int i = 0; i <= rowIndex; ++i) {
            result[i % 2][0] = 1;
            result[i % 2][i] = 1;
            for (int j = 1; j < i; ++j)
                result[i % 2][j] = result[(i - 1) % 2][j - 1] + result[(i - 1) % 2][j];
        }
        return result[rowIndex % 2];
    }
};