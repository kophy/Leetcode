class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

        return dp[nums.size() - 1];
    }
};

/*
	dp(n + 1) = max(dp(n), dp(n - 1) + nums[n + 1])
	if dp(n) > dp(n - 1) + nums[n + 1], steal the (n + 1)th house
	if dp(n) < dp(n - 1) + nums[n + 1], steal the nth house

	Q: will we ignore nth house when it can be stolen?
	A: that means dp[n] > dp[n - 1] + nums[n + 1] && dp[n] == dp[n - 1], which is impossible
*/