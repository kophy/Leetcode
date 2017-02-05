class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int l = 0, r = getNumberLength(x) - 1;
        while (l < r) {
            if (getKthDight(x, l) != getKthDight(x, r))
                return false;
            ++l, --r;
        }
        return true;
    }

private:
    int getNumberLength(int x) {
        int len = 0;
        for (; x; x /= 10)
            ++len;
        return len;
    }

    int getKthDight(int x, int k) {
        x /= pow(10, k);
        return x % 10;
    }
};