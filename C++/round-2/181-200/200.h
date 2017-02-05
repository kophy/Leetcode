class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    grow(grid, i, j);
                }
            }
        }
        return count;
    }

private:
    void grow(vector<vector<char>> &grid, int i , int j) {
        grid[i][j] = '@';
        if (i - 1 >= 0 && grid[i - 1][j] == '1')
            grow(grid, i - 1, j);
        if (i + 1 < grid.size() && grid[i + 1][j] == '1')
            grow(grid, i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == '1')
            grow(grid, i, j - 1);
        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1')
            grow(grid, i, j + 1);
    }
};