class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 1;
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};