class Solution {
public:
	int minPathSum(vector<vector<int>> &grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
			return 0;
		int M = grid.size(), N = grid[0].size();

		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == 0 && j == 0)
					continue;
				else if (i > 0 && j == 0)
					grid[i][j] += grid[i - 1][j];
				else if (i == 0 && j > 0)
					grid[i][j] += grid[i][j - 1];
				else
					grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);

			}
		}
		return grid[M - 1][N - 1];
	}
};