class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int M = matrix.size(), N = matrix[0].size();
        int i = 0, j = N - 1;
        while (i < M && j >= 0) {
            if (matrix[i][j] < target)
                ++i;
            else if (matrix[i][j] > target)
                --j;
            else
                return true;
        }
        return false;
    }
};