class Solution {
public:
    bool isPowerOfThree(int n) {
        /* Calculate maximum power of three in advance.
        long maxpower3 = 1;
        while (maxpower3 * 3 < INT_MAX)
            maxpower3 *= 3;
        */
        return n > 0 && (1162261467 % n == 0);
    }
};