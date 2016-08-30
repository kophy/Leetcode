class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return result;
        int d = 0, u = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;

        while (d <= u && l <= r) {
            for (int j = l; j <= r; ++j)
                result.push_back(matrix[d][j]);
            if (++d > u)
                break;
            for (int i = d; i <= u; ++i)
                result.push_back(matrix[i][r]);
            if (--r < l)
                break;
            for (int j = r; j >= l; --j)
                result.push_back(matrix[u][j]);
            if (--u < d)
                break;
            for (int i = u; i >= d; --i)
                result.push_back(matrix[i][l]);
            if (++l > r)
                break;
        }

        return result;
    }
};