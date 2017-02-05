class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; ++i) {
            int len = i;
            result.push_back(vector<int>(len + 1, 1));
            for (int j = 1; j < len; ++j)
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
        return result;
    }
};