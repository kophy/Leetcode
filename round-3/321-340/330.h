class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long reach = 0;
        int patch = 0, i = 0;
        while (reach < n) {
            if (i < nums.size() && reach + 1 >= nums[i]) {
                reach += nums[i];
                ++i;
            } else {
                reach += reach + 1;
                ++patch;
            }
        }
        return patch;
    }
};