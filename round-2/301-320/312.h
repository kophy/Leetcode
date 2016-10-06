class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int len = 1; len <= n; ++len) {
            for (int left = 1; left + len <= n + 1; ++left) {
                int right = left + len - 1;
                for (int i = left; i <= right; ++i)
                    dp[left][right] = max(dp[left][right],
                                          nums[left - 1] * nums[i] * nums[right + 1] + dp[left][i - 1] + dp[i + 1][right]);
            }
        }

        return dp[1][n];
    }
};