class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ) {
            int same = 0;
            while (i + same < nums.size() && nums[i + same] == nums[i])
                ++same;
            int previous_number = result.size();
            for (int j = 0; j < previous_number; ++j) {
                vector<int> temp = result[j];
                for (int k = 0; k < same; ++k) {
                    temp.push_back(nums[i]);
                    result.push_back(temp);
                }
            }
            i += same;
        }
        return result;
    }
};