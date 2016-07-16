class Solution {
public:
    int uniquePaths(int m, int n) {
        int data[2][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0)
                    data[i % 2][j] = 1;
                else
                    data[i % 2][j] = data[(i - 1) % 2][j] + data[i % 2][j - 1];
            }
        }
        return data[(m - 1) % 2][n - 1];
    }
};