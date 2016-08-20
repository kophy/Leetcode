class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> result(target + 1, 0);
        result[0] = 1;
        for(int t = 1; t <= target; ++t) {
            for (int i = 0; i < nums.size(); ++i) {
                if( t - nums[i] >= 0)
                    result[t] += result[t - nums[i]];
            }
        }
        return result[target];
    }
};