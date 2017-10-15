class Solution {
public:
    int numDistinctIslands(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        M = grid.size();
        N = grid[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        
        unordered_set<string> unique_islands;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (visited[i][j] || grid[i][j] == 0)
                    continue;
                string pattern;
                helper(pattern, grid, visited, i, j, 'S');
                unique_islands.insert(pattern);
            }
        }
        return unique_islands.size();
    }
    
private:
    int M, N;
    
    bool valid(int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }
    
    // generate pattern of an island through dfs
    void helper(string &pattern, vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, char direction) {
        if (!valid(i, j) || visited[i][j] || grid[i][j] != 1)
            return;
        visited[i][j] = true;
        string result = "";
        pattern += string(1, direction);
        
        int di[4] = {0, -1, 0, 1}, dj[4] = {-1, 0, 1, 0};
        char directions[4] = {'D', 'L', 'U', 'R'};
        for (int k = 0; k < 4; ++k) {
            // avoid paths of different directions mixing together
            pattern.push_back('(');
            helper(pattern, grid, visited, i + di[k], j + dj[k], directions[k]);
            pattern.push_back(')');
        }
    }
}; 