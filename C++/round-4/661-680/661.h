class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        if (M.empty() || M[0].empty())
            return M;
        vector<vector<int>> result(M.size(), vector<int>(M[0].size(), 0));
        for (int i = 0; i < M.size(); ++i)
            for (int j = 0; j < M[0].size(); ++j)
                result[i][j] = calculateAverage(M, i, j);
        return result;
    }
    
private:
    int calculateAverage(vector<vector<int>> &M, int i, int j) {
        int sum = 0, count = 0;
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < M.size() && nj >= 0 && nj < M[0].size()) {
                    sum += M[ni][nj];
                    count += 1;
                }
            }
        }
        return sum / count;
    }
};