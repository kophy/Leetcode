class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        unordered_map<int, int> count;
        for (int &num : nums)
            ++count[num];
        vector<vector<int>> result;
        vector<int> candidate;
        backtracking(result, count, candidate, nums.size());
        return result;
    }
    
private:
    void backtracking(vector<vector<int>> &result, unordered_map<int, int> &count, vector<int> &candidate, int N) {
        if (candidate.size() == N) {
            result.push_back(candidate);
            return;
        }
        for (auto &p : count) {
            if (p.second > 0) {
                --p.second;
                candidate.push_back(p.first);
                backtracking(result, count, candidate, N);
                candidate.pop_back();
                ++p.second;
            }
        }
    }
};