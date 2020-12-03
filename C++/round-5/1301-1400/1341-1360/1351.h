class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int M = grid.size(), N = grid[0].size();
        
        int result = 0;
        int first_non_negative_column = N - 1;
        for (int i = 0; i < M; ++i) {
            while (first_non_negative_column >= 0 && grid[i][first_non_negative_column] < 0) {
                --first_non_negative_column;
            }
            result += (N - first_non_negative_column - 1);
        }
        return result;
    }
};