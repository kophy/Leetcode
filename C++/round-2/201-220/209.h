class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int length = 0;
        int last = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (last < i && sum - nums[last] >= s) {
                sum -= nums[last];
                ++last;
            }
            if (sum >= s) {
                if (length == 0 || length > i - last + 1)
                    length = i - last + 1;
            }
        }
        return length;
    }
};