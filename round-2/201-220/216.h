class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        combine(result, k, n, 1, path);
        return result;
    }

private:
    void combine(vector<vector<int>> &result, int k, int n, int begin, vector<int> &path) {
        if (path.size() == k) {
            if (accumulate(path.begin(), path.end(), 0) == n)
                result.push_back(path);
            return;
        }
        for (int i = begin; i <= 9; ++i) {
            path.push_back(i);
            combine(result, k, n, i + 1, path);
            path.pop_back();
        }
    }
};