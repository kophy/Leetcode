class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 0;
		vector<int> temp(nums.size(), 0);
		int i = 0;
		while (i < nums.size()) {
		    int prev = nums[i];
		    temp[length++] = nums[i++];
		    int count = 0;
		    while (i < nums.size() && nums[i] == nums[i - 1]) {
		        ++i;
		        ++count;
		    }
		    if (count)
		        temp[length++] = prev;
		}
		nums = temp;
		return length;
    }
};