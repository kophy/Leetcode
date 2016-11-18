public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid.length == 0 || obstacleGrid[0].length == 0)
            return 0;
        int M = obstacleGrid.length, N = obstacleGrid[0].length;

        // start point itself may be unreachable
        int dp[][] = new int[M][N];

        dp[0][0] = (obstacleGrid[0][0] == 0)? 1 : 0;
        for (int i = 1; i < M; ++i)
            dp[i][0] = (obstacleGrid[i][0] == 0)? dp[i - 1][0] : 0;
        for (int j = 1; j < N; ++j)
            dp[0][j] = (obstacleGrid[0][j] == 0)? dp[0][j - 1] : 0;
        for (int i = 1; i < M; ++i)
            for (int j = 1; j < N; ++j)
                dp[i][j] = (obstacleGrid[i][j] == 0)? dp[i - 1][j] + dp[i][j - 1] : 0;

        return dp[M - 1][N - 1];
    }
}