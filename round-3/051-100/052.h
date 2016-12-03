class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        int max_sum = nums[0], curr_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            curr_sum = curr_sum > 0? curr_sum + nums[i] : nums[i];
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};