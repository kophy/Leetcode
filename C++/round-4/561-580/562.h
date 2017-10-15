class Solution {
public:
    int longestLine(vector<vector<int>> &M) {
        if (M.empty() || M[0].empty())
            return 0;
        
        int m = M.size(), n = M[0].size();
        vector<int> row(m, 0), col(n, 0), diag(m + n - 1, 0), antidiag(m + n - 1, 0);
        
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) {
                    ++row[i];
                    ++col[j];
                    ++diag[i + n - j - 1];
                    ++antidiag[i + j];
                    
                    vector<int> temp = {row[i], col[j], diag[i + n - j - 1], antidiag[i + j]};
                    result = max(result, *max_element(temp.begin(), temp.end()));
                } else {
                    row[i] = 0;
                    col[j] = 0;
                    diag[i + n - j - 1] = 0;
                    antidiag[i + j] = 0;
                }
            }
        }
        return result;
    }
};