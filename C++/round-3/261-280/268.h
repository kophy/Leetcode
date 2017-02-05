class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int result = 0;
        for (int i = 0; i < nums.size(); ++i)
            result ^= (i + 1) ^ nums[i];
        return result;
    }
};