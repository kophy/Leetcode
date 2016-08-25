class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0)
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        int result = INT_MIN;
        for (int l = 0; l < col; ++l) {
            vector<int> sums(row, 0);
            for (int j = l; j < col; ++j) {
                for (int i = 0; i < row; ++i)
                    sums[i] += matrix[i][j];
                set<int> sum_set;
                sum_set.insert(0);
                int cur_sum = 0, max_cur_sum = INT_MIN;
                for(int i = 0; i < sums.size(); ++i) {
                    cur_sum += sums[i];
                    auto iter = sum_set.lower_bound(cur_sum - k);
                    if (iter != sum_set.end())
                        max_cur_sum = max(max_cur_sum, cur_sum - *iter);
                    sum_set.insert(cur_sum);
                }
                result = max(result, max_cur_sum);
            }
        }
        return result;
    }
};