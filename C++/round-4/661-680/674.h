class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int result = 1;
		int begin = 0, end = 0;
		while (end < nums.size()) {
			while (end + 1 < nums.size() && nums[end] < nums[end + 1])
				++end;
			result = max(result, end - begin + 1);
			begin = end + 1;
			end = end + 1;
		}
		return result;
	}
};