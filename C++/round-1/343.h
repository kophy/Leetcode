class Solution {
public:
    int integerBreak(int n) {
        vector<int> max_product(n + 1, INT_MIN);

        max_product[1] = 1;
        max_product[2] = 1;

        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (max_product[i] < j * (i - j))
                    max_product[i] = j * (i - j);
                if (max_product[i] < j * max_product[i - j])
                    max_product[i] = j * max_product[i - j];
            }
        }
        return max_product[n];
    }
};