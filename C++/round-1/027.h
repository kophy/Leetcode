class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;
        for (; i < nums.size(); ++i) {
            if (nums[i] != val)
                nums[j++] = nums[i];
        }
        nums.resize(j);
        return j;
    }
};