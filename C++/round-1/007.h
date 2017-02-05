class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        else if (x < 0)
            return -reverse(-x);
        int result = 0;
        while (x) {
            if (result > INT_MAX / 10)
                return 0;
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
};