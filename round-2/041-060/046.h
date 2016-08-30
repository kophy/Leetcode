class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> path;
        permute_help(result, nums, used, path);
        return result;
    }

private:
    void permute_help(vector<vector<int>> &result, vector<int> &nums, vector<bool> used, vector<int> path) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                permute_help(result, nums, used, path);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};