class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        int result = 1;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                result = max(result, getLongestIncreasingPath(matrix, dp, i, j));
        return result;
    }

private:
    int M, N;

    int getLongestIncreasingPath(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
        if (dp[i][j])
            return dp[i][j];
        int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
        int temp = 0;
        for (int k = 0; k < 4; ++k)
            if (isValidIndex(i + di[k], j + dj[k]) && matrix[i][j] < matrix[i + di[k]][j + dj[k]])
                temp = max(temp, getLongestIncreasingPath(matrix, dp, i + di[k], j + dj[k]));
        dp[i][j] = temp + 1;
        return dp[i][j];
    }

    bool isValidIndex(int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }
};