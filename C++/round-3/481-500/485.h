class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int l = 0, r = 0;
        for (; r < nums.size(); ++r) {
            if (nums[r] != 1)
                l = r + 1;
            else
                result = max(result, r - l + 1);
        }
        return result;
    }
};