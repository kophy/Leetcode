class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int count = 1;
        int d = 0, u = n - 1, l = 0, r = n - 1;
        while (true) {
            for(int j = l; j <= r; ++j)
                result[d][j] = count++;
            if (++d > u)
                break;
            for (int i = d; i <= u; ++i)
                result[i][r] = count++;
            if (--r < l)
                break;
            for (int j = r; j >= l; --j)
                result[u][j] = count++;
            if (--u < d)
                break;
            for (int i = u; i >= d; --i)
                result[i][l] = count++;
            if (++l > r)
                break;
        }
        return result;
    }
};