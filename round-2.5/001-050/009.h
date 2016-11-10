// version 1: k-th digit
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int i = 0, j = log(x) / log(10);
        while (i < j)
            if (getKthDigit(x, i++) != getKthDigit(x, j--))
                return false;
        return true;
    }

private:
    int getKthDigit(int x, int k) {
        return (int)(x / pow(10, k)) % 10;
    }
};

// version 2: string reverse
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i = 0, j = s.size() - 1;
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
};