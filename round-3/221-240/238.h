class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        if (nums.size() <= 1)
            return result;
        int N = nums.size();
        int left = nums[0];
        for (int i = 1; i < N; ++i) {
            result[i] *= left;
            left *= nums[i];
        }
        int right = nums[N - 1];
        for (int i = N - 2; i >= 0; --i) {
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};