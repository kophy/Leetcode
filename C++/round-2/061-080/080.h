class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size()) {
            int same = 0;
            while (i + same < nums.size() && nums[i + same] == nums[i]) {
                ++same;
                if (same < 3)
                    nums[j++] = nums[i];
            }
            i += same;
        }
        return j;
    }
};