class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        M = grid.size(), N = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] == 1)
                    perimeter += validEdges(grid, i, j);
        return perimeter;
    }

private:
    int M, N;

    int validEdges(vector<vector<int>>& grid, int i, int j) {
        int count = 0;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (!isValidIndex(x, y) || grid[x][y] == 0)
                ++count;
        }
        return count;
    }

    bool isValidIndex(int x, int y) {
        return x >= 0 && x < M && y >= 0 && y < N;
    }
};