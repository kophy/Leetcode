class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long reach = 1, added = 0;
        int i = 0;
        while (reach <= n) {
            if (i < nums.size() && nums[i] <= reach)
                reach += nums[i++];
            else {
                ++added;
                reach <<= 1;
            }
        }
        return added;
    }
};