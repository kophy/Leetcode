class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0)
                nums[i] = nums.size();
        }
        for (int i = 0; i < nums.size(); ++i) {
            int n = abs(nums[i]);
            if (nums[n] < 0)
                return n;
            else
                nums[n] *= -1;
        }
        return 0;
    }
};