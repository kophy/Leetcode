class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num) {
            if (num == 1)
                return true;
            if (num & 0x0003)
                return false;
            num >>= 2;
        }
        return (num == 1);
    }
};