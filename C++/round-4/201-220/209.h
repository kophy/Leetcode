class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int result = INT_MAX;
		int l = 0, r = 0, sum = 0;
		for (; r < nums.size(); ++r) {
			sum += nums[r];
			if (sum < s)
				continue;
			while (l < r && sum - nums[l] >= s) {
				sum -= nums[l];
				++l;
			}
			result = min(result, r - l + 1);
		}
		return (result == INT_MAX)? 0 : result;
	}
};