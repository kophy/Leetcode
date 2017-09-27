class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int result = 0;
        backtracking(result, nums, 0, 0, S);
        return result;
    }
    
private:
    void backtracking(int &result, vector<int> &nums, int pos, int sum, int S) {
        if (pos == nums.size()) {
            if (sum == S)
                ++result;
            return;
        }
        backtracking(result, nums, pos + 1, sum + nums[pos], S);
        backtracking(result, nums, pos + 1, sum - nums[pos], S);
    }
};