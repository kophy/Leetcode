class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 1);
        int cnt2 = 0, cnt3 = 0, cnt5 = 0;
        for (int i = 1; i < n; ++i) {
            ugly[i] = min(ugly[cnt2] * 2, min(ugly[cnt3] * 3, ugly[cnt5] * 5));
            if (ugly[i] == ugly[cnt2] * 2)
                ++cnt2;
            if (ugly[i] == ugly[cnt3] * 3)
                ++cnt3;
            if (ugly[i] == ugly[cnt5] * 5)
                ++cnt5;
        }
        return ugly[n - 1];
    }
};