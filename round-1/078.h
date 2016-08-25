class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int total_number = 1 << nums.size();
        for (int i = 0; i < total_number; ++i) {
            vector<int> temp;
            int k = i;
            for (int j = 0; j < nums.size(); ++j) {
                if (k & 1)
                    temp.push_back(nums[j]);
                k >>= 1;
            }
            result.push_back(temp);
        }
        return result;
    }
};