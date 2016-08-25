class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> index;
		vector<int> result(2, -1);
		for (int i = 0; i < nums.size(); ++i) {
			if (index.find(target - nums[i]) != index.end()) {
				result[0] = index[target - nums[i]];
				result[1] = i;
				return result;
			}
			index[nums[i]] = i;
		}
        return result;
    }
};