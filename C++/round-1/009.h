class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0)
            return true;
        else if (x < 0)
            return false;
        int len = log(x) / log(10);
        cout << len << endl;
        for (int i = 0; i <= len / 2; ++i) {
            if (digitAt(x, i) != digitAt(x, len - i))
                return false;
        }
        return true;
    }
    int digitAt(int x, int i) {
        return (int)(x / pow(10, i)) % 10;
    }
};