class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> candidate;
        backtracking(result, k, n, 1, candidate);
        return result;
    }
    
private:
    void backtracking(vector<vector<int>> &result, int k, int n, int num, vector<int> &candidate) {
        if (k == 0) {
            if (n == 0)
                result.push_back(candidate);
            return;
        }
        for (; num <= 9 && num <= n; ++num) {
            candidate.push_back(num);
            backtracking(result, k - 1, n - num, num + 1, candidate);
            candidate.pop_back();
        }
    }
};