class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        for (int i = 0; i < len; ) {
            if (nums[i] == val)
                swap(nums[i], nums[--len]);
            else
                ++i;
        }
        return len;
    }
};