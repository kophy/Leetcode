class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int sum = 0, base = INT_MAX;
        for (auto num : nums) {
            sum += num;
            base = min(base, num);
        }
        return sum - base * nums.size();
    }
};