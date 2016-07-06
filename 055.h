class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> reachable(nums.size(), false);
        reachable[0] = true;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (reachable[j] && j + nums[j] >= i) {
                    reachable[i] = true;
                    break;
                }
            }
        }
        return reachable[nums.size() - 1];
    }
};