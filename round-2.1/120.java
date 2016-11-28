public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[][] opt = new int[n + 1][n + 1];

        // bottom-up, compress path
        for (int i = n - 1; i >= 0; --i)
            for (int j = 0; j <= i; ++j)
                opt[i][j] = Math.min(opt[i + 1][j], opt[i + 1][j + 1]) + triangle.get(i).get(j);
        return opt[0][0];
    }
}