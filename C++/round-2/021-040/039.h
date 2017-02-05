class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        combinationSum_help(result, candidates, target, 0, path);
        return result;
    }

private:
    void combinationSum_help(vector<vector<int>> &result, vector<int> &candidates, int target, int pos, vector<int> path) {
        int sum = accumulate(path.begin(), path.end(), 0);	// bottle-neck: a variable can be used to memorize temp sum

        if (sum == target) {
            result.push_back(path);
            return;
        }
		/*  two explicit end condition…
			although backtracking itself can end implicitly.
		*/
		if (sum > target || pos >= candidates.size())
			return;
		
        for (int i = pos; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            combinationSum_help(result, candidates, target, i, path);
            path.pop_back();
        }

    }
};