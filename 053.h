cclass Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n);
        sum[0] = nums[0];
        int max_sum = sum[0];
        for(int i = 1; i < n; i++) {
            sum[i] = nums[i] + ((sum[i - 1] > 0)? sum[i - 1] : 0);
            max_sum = max(max_sum, sum[i]);
        }
        return max_sum;
    }
};