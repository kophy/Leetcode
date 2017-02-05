class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int M = matrix.size(), N = matrix[0].size();

        vector<int> left(N, 0), right(N, M - 1), height(N, 0);
        int max_area = 0;
        for (int i = 0; i < M; ++i) {
            int curr_left = 0, curr_right = N - 1;
            // calculate the height of continuous 1 area
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    ++height[j];
            }
            // calculate the leftmost index of continuous 1 area
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == '0') {
                    left[j] = 0;
                    curr_left = j + 1;
                } else
                    left[j] = max(left[j], curr_left);
            }
            // calculate the rightmost index of continuous 1 area
            for (int j = N - 1; j >= 0; --j) {
                if (matrix[i][j] == '0') {
                    right[j] = N - 1;
                    curr_right = j - 1;
                } else
                    right[j] = min(right[j], curr_right);
            }

            for (int j = 0; j < N; ++j)
                max_area = max(max_area, (right[j] - left[j] + 1) * height[j]);

        }
        return max_area;
    }
};