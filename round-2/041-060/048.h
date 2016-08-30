class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        if (N == 0)
            return;

        /* rotate: m[i][j] <- m[N - j][N - i] */
        for (int i = 0; i < N / 2; ++i)
            for (int j = 0; j < N; ++j)
                swap(matrix[i][j], matrix[N - i - 1][j]);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};