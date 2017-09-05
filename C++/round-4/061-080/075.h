class Solution {
public:
	void sortColors(vector<int>& nums) {
		int red = 0, blue = (int)nums.size() - 1;
		int pos = 0;
		while (pos <= blue) {
			if (nums[pos] == 0)
				swap(nums[pos++], nums[red++]);
			else if (nums[pos] == 1)
				++pos;
			else
				swap(nums[pos], nums[blue--]);
		}
	}
};