// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int s = 1, e = n;
        while (s < e) {
            int m = s + (e - s) / 2;
            int flag = guess(m);
            if (flag == 0)
                return m;
            else if (flag > 0)
                s = m + 1;
            else
                e = m - 1;
        }
        return s;
    }
};