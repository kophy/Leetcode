class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum & 1? false : dfs(nums, sum / 2, 0);
    }

private:
    bool dfs(vector<int> &nums, int target, int curr) {
        if (target < 0)
            return false;
        else if (target == 0)
            return true;
        for (int i = curr; i < nums.size(); ++i)
            if (dfs(nums, target - nums[i], i + 1))
                return true;
        return false;
    }
};