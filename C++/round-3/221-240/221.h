class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int M = matrix.size(), N = matrix[0].size();
        vector<int> left(N, 0), right(N, N - 1), height(N, 0);
        int result = 0;
        for (int i = 0; i < M; ++i) {
            int curr_left = 0;
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == '0') {
                    left[j] = 0;
                    curr_left = j + 1;
                } else
                    left[j] = max(curr_left, left[j]);
            }
            int curr_right = N - 1;
            for (int j = N - 1; j >= 0; --j) {
                if (matrix[i][j] == '0') {
                    right[j] = N - 1;
                    curr_right = j - 1;
                } else
                    right[j] = min(curr_right, right[j]);
            }
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    ++height[j];
            }
            for (int j = 0; j < N; ++j) {
                int edge = min(height[j], right[j] - left[j] + 1);
                result = max(result, edge * edge);
            }
        }
        return result;
    }
};