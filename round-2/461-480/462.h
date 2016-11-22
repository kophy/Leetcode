class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int result = 0;
        for (auto num : nums)
            result += abs(num - median);
        return result;
    }
};