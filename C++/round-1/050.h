class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1 || n == 0)
            return 1;
        if (n == INT_MIN)
            return myPow(1 / x, INT_MAX) / x;
        if (n < 0)
            return myPow(1 / x, -n);
        double val = myPow(x, n/2);
        if (n & 1)
            return val * val * x;
        else
            return val * val;
    }
};