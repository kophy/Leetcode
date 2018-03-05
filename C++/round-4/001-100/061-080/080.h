class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0, j = 0;
		while (i < nums.size()) {
			int count = 0;
			while (i + count < nums.size() && nums[i + count] == nums[i])
				++count;
			for (int k = 0; k < min(2, count); ++k)
				nums[j++] = nums[i];
			i += count;
		}
		return j;
	}
};