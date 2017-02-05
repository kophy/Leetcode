class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        combine_help(result, n, k, 1, path);
        return result;
    }

private:
    void combine_help(vector<vector<int>> &result, int n, int k, int pos, vector<int> &path) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        if (pos > n)
            return;
        for (int i = pos; i <= n; ++i) {
            path.push_back(i);
            combine_help(result, n, k, i + 1, path);
            path.pop_back();
        }
    }
};