class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        n = min(n, 10);
        if (n == 0)
            return 1;
        int result = 10;
        for (int i = 2; i <= n; ++i) {
            int temp = 9;
            for (int j = 1; j < i; ++j)
                temp *= (10 - j);
            result += temp;
        }
        return result;
    }
};