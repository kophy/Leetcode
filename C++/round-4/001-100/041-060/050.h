class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            if (n == INT_MIN)
                return myPow(1 / x, INT_MAX) / x;
            else
                return myPow(1 / x, -n);
        }
        if (n == 0)
            return 1;
        double temp = myPow(x, n / 2);
        return (n % 2 == 1)? temp * temp * x : temp * temp;
    }
};