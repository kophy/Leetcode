class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();

        /* avoid cases when characters are the same */
        int k = skip_same(nums);
        if (k == nums.size() - 1)
            return 1;

        int result = 2;
        bool small = nums[k] > nums[k + 1];
        for (int i = k + 1; i < nums.size() - 1; ++i) {
            // nums[i] can be used to replace last number in subsequence
            // suppose a smaller number is required
            // than elements from last number in subsequence to num[i] forms a non-decreasing array
            // therefore last elements in subsequence can be replaced by num[i]
            if ((small && nums[i] < nums[i + 1]) || (!small && nums[i] > nums[i + 1])) {
                ++result;
                small = !small;
            }
        }
        return result;
    }

private:
    int skip_same(vector<int> &nums) {
        for (int i = 0; i < nums.size() - 1; ++i)
            if (nums[i] != nums[i + 1])
                return i;
        return nums.size() - 1;
    }
};