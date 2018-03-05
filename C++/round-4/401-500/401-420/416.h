class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0)
			return false;
		vector<bool> dp(sum + 1, false);
		dp[0] = true;
		for (int num : nums) {
			for (int j = sum; j >= num; --j)
				dp[j] = dp[j] || dp[j - num];
		}
		return dp[sum / 2];
	}
};