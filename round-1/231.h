class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n) {
            if (n & 1)
                return (n == 1);
            n >>= 1;
        }
        return false;
    }
};