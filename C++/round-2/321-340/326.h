class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        else
            return n == pow(3, round(log(n) / log(3)));
    }
};