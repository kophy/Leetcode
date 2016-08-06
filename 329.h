class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (!matrix.size())
            return 0;
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> distance(M, vector<int>(N, 0));

        int max_distance = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                search(matrix, distance, i, j);
                max_distance = max(max_distance, distance[i][j]);
            }
        }
        return max_distance;
    }
private:
    void search(vector<vector<int>> &matrix, vector<vector<int>> &distance, int i, int j) {
        if (distance[i][j])
            return;
        distance[i][j] = 1;
        if (i - 1 >= 0 && matrix[i][j] < matrix[i - 1][j]) {
            search(matrix, distance, i - 1, j);
            distance[i][j] = max(distance[i][j], distance[i - 1][j] + 1);
        }
        if (i + 1 < matrix.size() && matrix[i][j] < matrix[i + 1][j]) {
            search(matrix, distance, i + 1, j);
            distance[i][j] = max(distance[i][j], distance[i + 1][j] + 1);
        }
        if (j - 1 >= 0 && matrix[i][j] < matrix[i][j - 1]) {
            search(matrix, distance, i, j - 1);
            distance[i][j] = max(distance[i][j], distance[i][j - 1] + 1);
        }
        if (j + 1 < matrix[0].size() && matrix[i][j] < matrix[i][j + 1]) {
            search(matrix, distance, i, j + 1);
            distance[i][j] = max(distance[i][j], distance[i][j + 1] + 1);
        }
    }
};