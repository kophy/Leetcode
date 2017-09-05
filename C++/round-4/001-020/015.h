class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() < 3)
			return result;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); ) {
			int l = i + 1, r = nums.size() - 1;
			while (l < r) {
				int sum = nums[i] + nums[l] + nums[r];
				if (sum < 0)
					++l;
				else if (sum > 0)
					--r;
				else {
					vector<int> temp = {nums[i], nums[l], nums[r]};
					result.push_back(temp);
					++l;
					while (l < r && nums[l] == nums[l - 1])
						++l;
				}
			}
			++i;
			while (i < nums.size() && nums[i] == nums[i - 1])
				++i;
		}
		return result;
	}
};