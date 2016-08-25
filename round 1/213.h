class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> exclude_head(nums.begin() + 1, nums.end());
        vector<int> exclude_tail(nums.begin(), nums.end() - 1);
        return max(rob_original(exclude_head), rob_original(exclude_tail));
    }
private:
    int rob_original(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i)
            nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
        return nums.back();
    }
};