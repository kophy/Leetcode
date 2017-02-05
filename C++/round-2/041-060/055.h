class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (max_reach < i)
                return false;
            max_reach = max(max_reach, i + nums[i]);
            if (max_reach >= nums.size() - 1)
                return true;
        }
        return max_reach >= nums.size() - 1;
    }
};