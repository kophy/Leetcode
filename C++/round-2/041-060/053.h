class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> sum(nums.size());
        sum[0] = nums[0];
        int max_sum = sum[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] = (sum[i - 1] < 0)? nums[i] : sum[i - 1] + nums[i];
            max_sum = max(max_sum, sum[i]);
        }
        return max_sum;
    }
};