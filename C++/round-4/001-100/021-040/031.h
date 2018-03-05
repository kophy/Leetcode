class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = (int)nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i;
        // If we can't find an adjacent reverse pair, then it is the largest permutation.
        if (i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        // Find smallest nums[j] > nums[i], swap and reverse.
        int j = (int)nums.size() - 1;
        while (nums[j] <= nums[i])
            --j;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};