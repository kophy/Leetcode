class Solution {
public:
    int numTrees(int n) {
        if (n < 2)
            return 1;
        vector<int> result(n + 1, 0);
        result[0] = result[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j)
                result[i] += result[j] * result[i - j - 1];
        }
        return result[n];
    }
};