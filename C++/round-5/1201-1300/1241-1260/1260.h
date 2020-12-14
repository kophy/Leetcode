class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) {
            return grid;
        }
        int M = grid.size(), N = grid[0].size();
        k %= (M * N);
        
        vector<vector<int>> result(M, vector<int>(N, 0));
        for (int index = 0; index < M * N; ++index) {
            int i = index / N;
            int j = index % N;
            int new_i = ((index + k) % (M * N)) / N;
            int new_j = ((index + k) % (M * N)) % N;
            
            result[new_i][new_j] = grid[i][j];
        }
        return result;
    }
};