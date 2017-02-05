/* Solution 1: O(N^2) */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int result = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            result = max(result, dp[i]);
        }
        return result;
    }
};

/* Solution 2: O(NlgN) */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
for (int num : nums) {
            auto iter = lower_bound(result.begin(), result.end(), num);
            if (iter == result.end())
                result.push_back(num);
            else
                *iter = num;
        }
        return result.size();
    }
};