class Solution {
public:
    bool makesquare(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0 || nums.size() < 4)
            return false;
        vector<bool> used(nums.size(), false);
        return dfs(nums, used, sum / 4, 0, 0, 0);
    }

private:
    // use monotonic increasing index to avoid repeated search
    bool dfs(vector<int> &nums, vector<bool> &used, int edge_len, int edge_count, int temp_pos, int temp_len) {
        if (edge_count == 4)
            return true;
        for (int i = temp_pos; i < nums.size(); ++i) {
            if (used[i] || temp_len + nums[i] > edge_len)
                continue;
            else if (temp_len + nums[i] < edge_len) {
                used[i] = true;
                if (dfs(nums, used, edge_len, edge_count, i + 1, temp_len + nums[i]))
                    return true;
                used[i] = false;
            } else {
                used[i] = true;
                if (dfs(nums, used, edge_len, edge_count + 1, 0, 0))
                    return true;
                used[i] = false;
            }
        }
        return false;
    }
};