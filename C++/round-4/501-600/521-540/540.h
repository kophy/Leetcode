class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int l = 0, r = nums.size() / 2;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[2 * m] != nums[2 * m + 1])
                r = m;
            else
                l = m + 1;
        }
        return nums[2 * l];
    }
};