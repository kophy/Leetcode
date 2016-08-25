class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    markIsland(grid, i, j);
                }
            }
        }
        return count;
    }
private:
    void markIsland(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> data;
        grid[i][j] = '@';
        pair<int, int> seed(i, j);
        data.push(seed);
        while (!data.empty()) {
            pair<int, int> temp = data.front();
            data.pop();
            if (temp.first - 1 >= 0 && grid[temp.first - 1][temp.second] == '1') {
                data.push(pair<int, int>(temp.first - 1, temp.second));
                grid[temp.first - 1][temp.second] = '@';
            }
            if (temp.second - 1 >= 0 && grid[temp.first][temp.second - 1] == '1') {
                data.push(pair<int, int>(temp.first, temp.second - 1));
                grid[temp.first][temp.second - 1] = '@';
            }
            if (temp.first + 1 < grid.size() && grid[temp.first + 1][temp.second] == '1') {
                data.push(pair<int, int>(temp.first + 1, temp.second));
                grid[temp.first + 1][temp.second] = '@';
            }
            if (temp.second + 1 < grid[0].size() && grid[temp.first][temp.second + 1] == '1') {
                data.push(pair<int, int>(temp.first, temp.second + 1));
                grid[temp.first][temp.second + 1] = '@';
            }
        }
    }
};