public class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0)
            return new int[0];
        int M = matrix.length, N = matrix[0].length;
        int[] result = new int[M * N];
        boolean up = true;
        int k = 0;
        for (int sum = 0; sum < M + N + 1; ++sum) {
            if (up) {
                int b = Integer.min(M - 1, sum), e = Integer.max(0, sum - N + 1);
                for (int i = b; i >= e; --i)
                    result[k++] = matrix[i][sum - i];
            } else {
                int b = Integer.max(0, sum - N + 1), e = Integer.min(M, sum + 1);
                for (int i = b; i < e; ++i)
                    result[k++] = matrix[i][sum - i];
            }
            up = !up;
        }
        return result;
    }
}