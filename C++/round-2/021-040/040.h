class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        combinationSum2_help(result, candidates, target, 0, path);
        return result;
    }

private:
    void combinationSum2_help(vector<vector<int>> &result, vector<int> &candidates, int target, int pos, vector<int> path) {
        int sum = accumulate(path.begin(), path.end(), 0);
        if (sum == target) {
            result.push_back(path);
            return;
        }
        if (sum > target || pos >= candidates.size())
            return;
        for (int i = pos; i < candidates.size(); ) {
            path.push_back(candidates[i]);
            combinationSum2_help(result, candidates, target, i + 1, path);	// i + 1 because the same element can not be re-used.
            path.pop_back();

            /* the old trick to skip elements with same value */
            ++i;
            while (i < candidates.size() && candidates[i] == candidates[i - 1])
                ++i;
        }
    }
};