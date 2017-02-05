class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return (int)(n & (n - 1)) == 0;
    }
};