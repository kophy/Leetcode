class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            nums[i + 1] += nums[i];
        }
        return nums;
    }
};