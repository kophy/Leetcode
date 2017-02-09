public class Solution {
    public int[] constructRectangle(int area) {
        int[] result = new int[2];
        int bound = (int)Math.sqrt(area), diff = Integer.MAX_VALUE;
        for (int i = 1; i <= bound; ++i) {
            if (area % i == 0 && Math.abs(area / i - i) < diff) {
                result[0] = area / i;
                result[1] = i;
            }
        }
        return result;
    }
}