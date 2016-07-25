class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;
        int begin = 0;
        combine_helper(result, n, k, curr, begin);
        return result;
    }
private:
    void combine_helper(vector<vector<int>> &result, int n, int k, vector<int> &curr, int begin) {
        if (curr.size() == k) {
            result.push_back(curr);
            return;
        }
        for (int i = begin;  n - i >= k - curr.size(); ++i) {
            curr.push_back(i + 1);
            combine_helper(result, n, k, curr, i + 1);
            curr.pop_back();
        }
    }
};