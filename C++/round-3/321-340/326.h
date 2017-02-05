class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 1)
            return (n == 1);
        else
            return (pow(3, round(log(n) / log(3))) == n);
    }
};