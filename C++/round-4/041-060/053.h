class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int curr_sum = nums[0]; // largest sum ending with current element
        for (int i = 1; i < nums.size(); ++i) {
            curr_sum = max(curr_sum + nums[i], nums[i]);
            result = max(result, curr_sum);
        }
        return result;
    }
};