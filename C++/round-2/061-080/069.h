class Solution {
public:
    /*  Newton's method:
    	https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
    */
    int mySqrt(int x) {
        double r = x;
        while (abs(r * r - x) > 0.01)
            r = (r + x / r) / 2;
        return r;
    }
};