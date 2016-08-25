class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, sum = 0;
        int min_len = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= s) {
                min_len = min(min_len, i - start + 1);
                sum -= nums[start++];
            }
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};