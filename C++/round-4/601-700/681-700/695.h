class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        
        int M = grid.size(), N = grid[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        
        int max_island = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0 || visited[i][j])
                    continue;
                int island = 0;
                growIsland(island, grid, visited, i, j);
                max_island = max(max_island, island);
            }
        }
        return max_island;
    }
    
private:
    void growIsland(int &island, vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j) {
        int M = grid.size(), N = grid[0].size();
        if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 0 || visited[i][j])
            return;
        ++island;
        visited[i][j] = true;
        
        int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
        for (int k = 0; k < 4; ++k)
            growIsland(island, grid, visited, i + di[k], j + dj[k]);
    }
};