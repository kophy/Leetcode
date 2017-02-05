class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());

        for (int i = 0; i < nums.size(); ++i) {
            int N = result.size();
            for (int j = 0; j < N; ++j) {
                vector<int> temp = result[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }

        return result;
    }
};