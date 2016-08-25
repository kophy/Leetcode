class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        int curr_idx = 0;
        int curr_sum = 0;
        vector<int> curr;
        combinationSum2_help(result, candidates, target, curr_idx, curr_sum, curr);
        return result;
    }
private:
    void combinationSum2_help(vector<vector<int>> &result, vector<int> &candidates,
    int target, int curr_idx, int curr_sum, vector<int> curr) {
        if (curr_sum == target) {
            result.push_back(curr);
            return;
        }
        if (curr_sum > target || curr_idx >= candidates.size())
            return;
        int i = curr_idx;
        while (i < candidates.size()) {
            curr.push_back(candidates[i]);
            combinationSum2_help(result, candidates, target, i + 1, curr_sum + candidates[i], curr);
            curr.pop_back();
            ++i;
            while (i < candidates.size() && candidates[i] == candidates[i - 1])
                ++i;
        }
    }
};