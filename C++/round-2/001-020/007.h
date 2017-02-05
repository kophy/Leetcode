class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        if (x < 0)
            return -reverse(-x);

        /* trick: use long type to avoid overflow of int type */
        long xl = x, result = 0;
        while (xl) {
            result = result * 10 + (xl % 10);
            if (result > INT_MAX)
                return 0;
            xl /= 10;
        }
        return result;
    }
};