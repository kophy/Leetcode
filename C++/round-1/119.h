class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> data;
        for (int i = 0; i < 2; ++i)
            data.push_back(vector<int>(rowIndex + 1));
        for (int i = 0; i <= rowIndex; ++i) {
            data[i % 2][0] = 1;
            data[i % 2][i] = 1;
            for (int j = 1; j < i; ++j)
                data[i % 2][j] = data[(i - 1) % 2][j - 1] + data[(i - 1) % 2][j];
        }
        return data[rowIndex % 2];
    }
};