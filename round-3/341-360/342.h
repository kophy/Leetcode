class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 1)
            return (num == 1);
        while (num > 1) {
            if (num & 3)
                return false;
            num >>= 2;
        }
        return (num == 1);
    }
};