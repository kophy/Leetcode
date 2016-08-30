class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (l >= nums.size() || nums[l] != target)
            return result;
        int u = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        /*  lower_bound finds the first element >= target
        	upper_bound finds the first element > target
        */
        result[0] = l;
        result[1] = u - 1;
        return result;
    }
};