class Solution {
public:
    int climbStairs(int n) {
        vector<int> number(n + 1, 0);
        number[1] = 1;
        number[2] = 2;

        for (int i = 3; i <= n; ++i)
            number[i] = number[i - 1] + number[i - 2];
        return number[n];
    }
};