class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int result = INT_MIN;
        for (int l = 0; l < matrix[0].size(); ++l) {
            vector<int> row_sum(matrix.size(), 0);
            for (int r = l; r < matrix[0].size(); ++r) {
                for (int c = 0; c < matrix.size(); ++c)
                    row_sum[c] += matrix[c][r];
                set<int> appeared_sums;
                appeared_sums.insert(0);
                int current_sum = 0;
                for (int c = 0; c < matrix.size(); ++c) {
                    current_sum += row_sum[c];
                    auto iter = appeared_sums.lower_bound(current_sum - k);
                    if (iter != appeared_sums.end())
                        result = max(result, current_sum - *iter);
                    appeared_sums.insert(current_sum);
                }
            }
        }
        return result;
    }
};