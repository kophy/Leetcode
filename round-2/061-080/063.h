class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[m][n];
        dp[0][0] = (obstacleGrid[0][0] == 1)? 0 : 1;

        /* process the first row and the first column */
        for (int i = 1; i < m; ++i) {
            if (dp[i - 1][0] > 0 && obstacleGrid[i][0] == 0)
                dp[i][0] = 1;
            else
                dp[i][0] = 0;
        }
        for (int j = 1; j < n; ++j) {
            if (dp[0][j - 1] > 0 && obstacleGrid[0][j] == 0)
                dp[0][j] = 1;
            else
                dp[0][j] = 0;
        }

        /* process other locations */
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};