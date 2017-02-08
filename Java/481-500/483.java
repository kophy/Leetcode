public class Solution {
    public String smallestGoodBase(String n) {
        long num = Long.parseLong(n);
        for (int p = 63; p >= 1; --p) {
            if (Math.pow(2, p) >= num)
                continue;
            long base = goodBaseHelper(num, p);
            if (base != -1)
                return String.valueOf(base);
            
        }
        return String.valueOf(num - 1);
    }
    
    /* sum geometric series: 1 + x + x^2 + ... + x^p */
    private long getGeometricsSum(long base, int p) {
        long sum = 0, curr = 1;
        for (int i = 0; i <= p; ++i) {
            sum += curr;
            curr *= base;
        }
        return sum;
    }
    
    /* find right x through binary search */
    private long goodBaseHelper(long num, int p) {
        long low = 2, high = (long)(Math.pow(num, 1.0 / p) + 1);
        while (low < high) {
            long mid = low + (high - low) / 2;
            long sum = getGeometricsSum(mid, p);
            if (sum == num)
                return mid;
            else if (sum > num)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
}