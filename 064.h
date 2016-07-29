class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        for (int j = 1; j < N; ++j)
            grid[0][j] += grid[0][j - 1];
        for (int i = 1; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (j == 0)
                    grid[i][j] += grid[i - 1][j];
                else
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[M - 1][N - 1];
    }
};