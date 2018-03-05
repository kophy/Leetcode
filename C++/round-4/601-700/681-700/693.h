class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = -1;
        while (n > 0) {
            if (n % 2 == last)
                return false;
            last = n % 2;
            n /= 2;
        }
        return true;
    }
};