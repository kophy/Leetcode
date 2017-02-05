class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int global_max = INT_MIN, global_min = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            global_max = max(global_max, nums[i]);
            global_min = min(global_min, nums[i]);
        }
        if (global_max == global_min)
            return 0;
        int average_gap = ceil(double(global_max - global_min) / (nums.size() - 1));

        vector<int> bucketMax(nums.size(), INT_MIN), bucketMin(nums.size(), INT_MAX);

        for (int i = 0; i < nums.size(); ++i) {
            int idx = (nums[i] - global_min) / average_gap;
            bucketMax[idx] = max(bucketMax[idx], nums[i]);
            bucketMin[idx] = min(bucketMin[idx], nums[i]);
        }
        int max_gap = average_gap, last_max = global_min;
        for (int i = 0; i < nums.size(); ++i) {
            if (bucketMin[i] != INT_MAX) {
                max_gap = max(max_gap, bucketMin[i] - last_max);
                last_max = bucketMax[i];
            }
        }
        return max_gap;
    }
};