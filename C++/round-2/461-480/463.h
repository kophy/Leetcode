class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        M = grid.size(), N = grid[0].size();
        int result = 0;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                if (grid[i][j] == 1)
                    result += countEdges(grid, i, j);
        return result;
    }

private:
    int M, N;

    bool valid(int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }

    int countEdges(vector<vector<int>> &grid, int i, int j) {
        int count = 0;
        int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
        for (int k = 0; k < 4; ++k) {
            int m = i + di[k], n = j + dj[k];
            if (!valid(m, n) || grid[m][n] == 0)
                ++count;
        }
        return count;
    }
};