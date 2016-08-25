class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int data[m][n];
        if (obstacleGrid[0][0])
            return 0;
        data[0][0] = 1;
        for (int j = 1; j < n; ++j)
            data[0][j] = data[0][j - 1] & (1 - obstacleGrid[0][j]);
        for (int i = 1; i < m; ++i)
            data[i][0] = data[i - 1][0] & (1 - obstacleGrid[i][0]);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j])
                    data[i][j] = 0;
                else
                    data[i][j] = data[i - 1][j] + data[i][j - 1];
            }
        }
        return data[m - 1][n - 1];
    }
};