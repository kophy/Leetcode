public class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        int k = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++k;
        }
        return (m << k);
    }
}