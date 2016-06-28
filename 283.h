class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i])
                nums[curr++] = nums[i];
        for (; curr < nums.size(); ++curr)
            nums[curr] = 0;
    }
};