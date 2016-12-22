class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() <= 0)
            return 0;
        int sum = 0, min_val = INT_MAX;
        for (int num : nums) {
            sum += num;
            min_val = min(min_val, num);
        }
        return sum - min_val * nums.size();
    }
};