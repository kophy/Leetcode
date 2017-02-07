public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0)
            return false;
        int M = matrix.length, N = matrix[0].length;
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
}