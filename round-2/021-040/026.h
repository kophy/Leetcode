class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        int len = 1;
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] != nums[len - 1])
                nums[len++] = nums[i];
        return len;
    }
};