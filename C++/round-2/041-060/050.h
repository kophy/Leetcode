class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        else if (n == 0)
            return 1;

        /* old trap of INT_MIN */
        else if (n < 0)
            return (n == INT_MIN)? myPow(1/x, INT_MAX) / x : myPow(1/x, -n);
        else {
            double temp = myPow(x, n / 2);
            return (n % 2)? temp * temp * x : temp * temp;
        }
    }
};