class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int M = grid.size(), N = grid[0].size();
        
        vector<int> rows(M, 0), columns(N, 0);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                ++rows[i];
                ++columns[j];
            }
        }
        
        int result = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                if (rows[i] <= 1 && columns[j] <= 1) {
                    continue;
                }
                ++result;
            }
        }
        return result;
    }
};