class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> curr;
        permute_helper(result, nums, used, curr);
        return result;
    }
private:
    void permute_helper(vector<vector<int>> &result, vector<int> & nums, vector<bool> used, vector<int> curr) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                curr.push_back(nums[i]);
                used[i] = true;
                permute_helper(result, nums, used, curr);
                used[i] = false;
                curr.pop_back();
            }
        }
    }
};