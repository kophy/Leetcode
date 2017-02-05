class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        sort(nums.begin(), nums.end());
        int pos = 0;
        while (pos < nums.size()) {
            int count = 0;
            for (int i = 0; pos + i < nums.size() && nums[pos + i] == nums[pos]; ++i)
                ++count;
            int N = result.size();
            for (int i = 0; i < N; ++i) {
                vector<int> temp = result[i];
                for (int j = 0; j < count; ++j) {
                    temp.push_back(nums[pos]);
                    result.push_back(temp);
                }
            }
            pos += count;
        }
        return result;
    }
};