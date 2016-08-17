class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        combinationSum3_help(result, k, n, 1, path);
        return result;
    }

private:
    void combinationSum3_help(vector<vector<int>> &result, int k, int n, int pos, vector<int> path) {
        if (path.size() == k) {
            if (accumulate(path.begin(), path.end(), 0) == n)
                result.push_back(path);
        }
        if (pos >= 10)
            return;
        for (int i = pos; i < 10; ++i) {
            path.push_back(i);
            combinationSum3_help(result, k, n, i + 1, path);
            path.pop_back();
        }
    }
};