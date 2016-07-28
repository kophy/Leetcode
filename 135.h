class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> num(ratings.size(), 1);
        for (int i = 1; i < num.size(); ++i)
            if (ratings[i] > ratings[i - 1])
                num[i] = num[i - 1] + 1;
        for (int i = num.size() - 2; i >= 0; --i)
            if (ratings[i] > ratings[i + 1])
                num[i] = max(num[i], num[i + 1] + 1);
        return accumulate(num.begin(), num.end(), 0);
    }
};