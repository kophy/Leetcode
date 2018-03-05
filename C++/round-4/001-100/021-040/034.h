class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result(2, -1);
		auto lower = lower_bound(nums.begin(), nums.end(), target);
		auto upper = upper_bound(nums.begin(), nums.end(), target);

		if (lower != nums.end() && *lower == target) {
			result[0] = lower - nums.begin();
			result[1] = upper - nums.begin() - 1;
		}
		return result;
	}
};