class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
		int temp = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			result[i] *= temp;
			temp *= nums[i];
		}
		temp = nums[nums.size() - 1];
		for (int i = nums.size() - 2; i >= 0; --i) {
			result[i] *= temp;
			temp *= nums[i];
		}
		return result;
    }
};