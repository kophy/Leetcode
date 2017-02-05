class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        M = matrix.size(), N = matrix[0].size();
        length = vector<vector<int>>(M, vector<int>(N, 0));
        int max_length = 0;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                max_length = max(max_length, findLongestPath(matrix, i, j));
        return max_length;
    }

private:
    int M, N;
    vector<vector<int>> length;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

    bool valid(int i, int j) {
        return i >= 0 && i < M && j >= 0 && j < N;
    }

    int findLongestPath(vector<vector<int>> &matrix, int i, int j) {
        if (length[i][j] > 0)
            return length[i][j];

        // actually no need to mark...monotonic
        int temp = matrix[i][j];
        matrix[i][j] = INT_MIN;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (valid(x, y) && matrix[x][y] > temp)
                length[i][j] = max(length[i][j], findLongestPath(matrix, x, y) + 1);
        }
        length[i][j] = max(length[i][j], 1);
        matrix[i][j] = temp;
        return length[i][j];
    }
};