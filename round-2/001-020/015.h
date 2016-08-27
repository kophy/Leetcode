class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		
		for (int i = 0; i < nums.size(); ) {
			for (int j = i + 1; j < nums.size(); ) {
				for (int k = nums.size() - 1; k > j; ) {
					int sum = nums[i] + nums[j] + nums[k];
					if (sum < 0)
						break;
					if (sum == 0) {
						vector<int> temp(3);
						temp[0] = nums[i], temp[1] = nums[j], temp[2] = nums[k];
						result.push_back(temp);
						break;
					}
					--k;
					while (k > j && nums[k] == nums[k + 1])
						--k;
				}
				++j;
				while (j < nums.size() && nums[j] == nums[j - 1])
					++j;
			}
			/* skip elements with same value */
			++i;
			while (i < nums.size() && nums[i] == nums[i - 1])
				++i;
		}
		return result;
    }
};