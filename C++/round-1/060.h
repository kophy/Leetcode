class Solution {
public:
    string getPermutation(int n, int k) {
        --k;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
            nums[i] = i + 1;

        vector<int> factorial(n, 1);
        for (int i = 1; i < n; ++i)
            factorial[i] = i * factorial[i - 1];

        string result = "";
        for (int i = n; i > 0; --i) {
            int idx = k / factorial[i - 1];
            result.push_back('0' + nums[idx]);
            nums.erase(nums.begin() + idx);
            k %= factorial[i - 1];
        }
        return result;
    }
};