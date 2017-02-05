class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        M = grid.size(), N = grid[0].size();
        int result = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != '1')
                    continue;
                ++result;
                growIsland(grid, i, j);
            }
        }
        return result;
    }
    
private:
    int M, N;
    
    bool isValidIndex(int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }
    
    void growIsland(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = 'x';
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (isValidIndex(x, y) && grid[x][y] == '1')
                growIsland(grid, x, y);
        }
    }
};