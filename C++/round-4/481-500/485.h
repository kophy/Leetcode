class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int result = 0;
        int pos = 0;
        while (pos < nums.size()) {
            while (pos < nums.size() && nums[pos] == 0)
                ++pos;
            int len = 0;
            while (pos < nums.size() && nums[pos] == 1) {
                ++pos;
                ++len;
            }
            result = max(result, len);
        }
        return result;
    }
};