class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        vector<int> lis(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if ((nums[i] > nums[j]) && (lis[j] + 1 > lis[i]))
                    lis[i] = lis[j] + 1;
            }
        }
        int max_lis = 0;
        for (int i = 0; i < lis.size(); ++i)
            if (max_lis < lis[i])
                max_lis = lis[i];
        return max_lis;
    }
};