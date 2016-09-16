class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 1);
        int ct2 = 0, ct3 = 0, ct5 = 0;
        for (int i = 1; i < n; ++i) {
            ugly[i] = min(ugly[ct2] * 2, min(ugly[ct3] * 3, ugly[ct5] * 5));

            // suppose this if statement requires to execute multiple times, then
            // ugly[ct2] * 2 is already in the array, so ct2 won't point at this position -- a paradox.
            if (ugly[i] >= ugly[ct2] * 2)
                ++ct2;
            if (ugly[i] >= ugly[ct3] * 3)
                ++ct3;
            if (ugly[i] >= ugly[ct5] * 5)
                ++ct5;
        }
        return ugly[n - 1];
    }
};