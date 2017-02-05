class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        else
            return max(rob_row(nums, 0, nums.size() - 1), rob_row(nums, 1, nums.size()));
    }

private:
    int rob_row(vector<int> &nums, int begin, int end) {
        int included = 0, excluded = 0;
        for (int i = begin; i < end; ++i) {
            int temp = included;
            included = excluded + nums[i];
            excluded = max(excluded, temp);
        }
        return max(included, excluded);
    }
};