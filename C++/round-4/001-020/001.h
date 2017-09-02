class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> val2idx;
		for (int i = 0; i < nums.size(); ++i) {
			if (val2idx.find(target - nums[i]) != val2idx.end())
				return vector<int>({val2idx[target - nums[i]], i});
			val2idx[nums[i]] = i;
		}
		return vector<int>(2, -1);
    }
};