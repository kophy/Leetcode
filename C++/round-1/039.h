class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> count;
        combinationSum_help(result, candidates, target, count);
        return result;
    }
private:
    void combinationSum_help(vector<vector<int>>& result, vector<int>& candidates, int target, vector<int> count) {
        if (target == 0) {
            vector<int> temp;
            for (int i = 0; i < count.size(); ++i)
                for (int j = 0; j < count[i]; ++j)
                    temp.push_back(candidates[i]);
            result.push_back(temp);
        } else if (target > 0 && count.size() < candidates.size()) {
            int idx = count.size();
            count.push_back(0);
            for (int i = 0; candidates[idx] * i <= target; ++i) {
                count[idx] = i;
                combinationSum_help(result, candidates, target - candidates[idx] * i, count);
            }
        }
    }
};