class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (!matrix.size() || !matrix[0].size())
            return result;
        int M = matrix.size(), N = matrix[0].size();
        int u = 0, d = M - 1, l = 0, r = N - 1;
        while (true) {
            for (int j = l; j <= r; ++j)
                result.push_back(matrix[u][j]);
            if (++u > d)
                break;
            for (int i = u; i <= d; ++i)
                result.push_back(matrix[i][r]);
            if (--r < l)
                break;
            for (int j = r; j >= l; --j)
                result.push_back(matrix[d][j]);
            if (--d < u)
                break;
            for (int i = d; i >= u; --i)
                result.push_back(matrix[i][l]);
            if (++l > r)
                break;
        }
        return result;
    }
};