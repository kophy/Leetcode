public class Solution {
    public int reverse(int x) {
        int sign = (x >= 0)? 1 : -1;
        long result = 0;
        for (x = Math.abs(x); x != 0; x /= 10) {
            result = result * 10 + x % 10;
            if (result < Integer.MIN_VALUE || result > Integer.MAX_VALUE)
                return 0;
        }
        return sign * (int)result;
    }
}