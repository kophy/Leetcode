class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (nums.size() == 1 || sum % 2 == 1)
			return false;
		int target = sum / 2;
		vector<bool> dp(target + 1, false);
		dp[0] = true;

		// classic pattern when each item can be used only once
		for (int num : nums)
			for (int i = target; i >= num; --i)
				dp[i] = dp[i] || dp[i - num];
		return dp[target];
	}
};