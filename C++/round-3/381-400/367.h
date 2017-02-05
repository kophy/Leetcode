class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 1)
            return (num == 1);
        long s = 0, e = num / 2;
        while (s <= e) {
            long m = (s + e) / 2;
            long temp = m * m;
            if (temp == num)
                return true;
            else if (temp < num)
                s = m + 1;
            else
                e = m - 1;
        }
        return false;
    }
};