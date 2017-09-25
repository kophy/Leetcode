class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        M = matrix.size();
        N = matrix[0].size();
        
        vector<vector<int>> dp(M, vector<int>(N, 0));
        int result = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = findLongestIncreasingPath(dp, matrix, i, j);
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
    
private:
    int M, N;
    
    bool isValidIndex(int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }
    
    int findLongestIncreasingPath(vector<vector<int>> &dp, vector<vector<int>> &matrix, int i, int j) {
        if (dp[i][j] > 0)
            return dp[i][j];
        dp[i][j] = 1;
        int di[] = {-1, 0, 1, 0}, dj[] = {0, -1, 0, 1};
        for (int k = 0; k < 4; ++k) {
            int ni = i + di[k], nj = j + dj[k];
            if (!isValidIndex(ni, nj) || matrix[i][j] >= matrix[ni][nj])
                continue;
            dp[i][j] = max(dp[i][j], 1 + findLongestIncreasingPath(dp, matrix, ni, nj));
        }
        return dp[i][j];
    }
};