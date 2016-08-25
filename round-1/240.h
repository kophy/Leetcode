class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int col = matrix[0].size() - 1;
        int row = 0;
        while(col >= 0 && row < matrix.size()) {
            if(target == matrix[row][col])
                return true;
            else if(target < matrix[row][col])
                --col;
            else if(target > matrix[row][col])
                ++row;
        }
        return false;
    }
};