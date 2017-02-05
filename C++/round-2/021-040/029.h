class Solution {
public:
    int divide(int dividend, int divisor) {
        /* all cases with overflow */
        if (divisor == 0 || (divisor == -1 && dividend == INT_MIN))
            return INT_MAX;
        int sign = (divisor < 0) ^ (dividend < 0)? -1 : 1;

        /* old trick of using long to handle labs(INT_MIN) */
        long dvd = labs(dividend), dvs = labs(divisor);
        int result = 0;
        while (dvd >= dvs) {
            long temp = dvs; // *** important: must use long type to avoid overflow! ***
            int m = 1;
            while (dvd >= temp * 2) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            result += m;
        }
        return sign * result;
    }
};