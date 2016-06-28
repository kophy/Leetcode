class Solution {
public:
    int mySqrt(int x) {
        double r = x;
        double delta = 0.1;
        while (abs(r * r - x) > delta)
            r = r - (r * r - x) / (2 * r);
        return r;
    }
};