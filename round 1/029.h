class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;

        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        int result = 0;
        while (dvd >= dvs) {
            long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            result += multiple;
        }
        return sign == 1 ? result : -result;
    }
};