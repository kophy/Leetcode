class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> curr;
        permuteUnique_help(result, nums, used, curr);
        return result;
    }
private:
    void permuteUnique_help(vector<vector<int>> &result, vector<int> &nums, vector<bool> used, vector<int> curr) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
        for (int i = 0; i < used.size(); ++i) {
            if (!used[i]) {
                if (i && nums[i] == nums[i - 1] && used[i - 1])
                    return
                        curr.push_back(nums[i]);
                used[i] = true;
                permuteUnique_help(result, nums, used, curr);
                curr.pop_back();
                used[i] = false;
            }
        }
    }
};