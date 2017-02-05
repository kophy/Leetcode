class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        for (long m = 1; m <= n; m *= 10) {
            int a = n / m, b = n % m;
            // case 1: a >= 8
            ones += (a + 8) / 10 * m;
            // case 2: a == 1
            ones += (a % 10 == 1) * (b + 1);
        }
        return ones;
    }
};