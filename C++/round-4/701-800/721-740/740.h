class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> values(10001, 0);
        for (int num : nums)
            values[num] += num;
        int skip = 0, take = 0;
        for (int value : values) {
            int temp = skip;
            skip = max(skip, take);
            take = temp + value;
        }
        return max(skip, take);
    }
};