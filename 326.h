class Solution {
public:
    bool isPowerOfThree(int n) {
        double delta = 0.00000000001;
        double result = log(n) / log(3);
        return abs(result - round(result)) < delta;
    }
};