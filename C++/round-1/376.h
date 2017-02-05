class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int k = 0;
        while (k < nums.size() - 1 && nums[k] == nums[k + 1])
            ++k;
        if (k == nums.size() - 1)
            return 1;
        int result = 2;
        bool small = nums[k] > nums[k + 1];
        for (int i = k + 1; i < nums.size() - 1; ++i) {
            if (small && nums[i] < nums[i + 1] || !small && nums[i] > nums[i + 1]) {
                ++result;
                small = !small;
            }
        }
        return result;
    }
};