class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        nums.push_back(INT_MAX);
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int m = (l + r) / 2;
			if (nums[m] == target)
				return m;
			else if (nums[m] > target)
				r = m;
			else
				l = m + 1;
		}
		return r;
    }
};