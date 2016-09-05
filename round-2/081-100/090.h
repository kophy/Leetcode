class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        result.push_back(vector<int>());

        int i = 0;
        while (i < nums.size()) {
            int same = 0;
            while (i + same < nums.size() && nums[i + same] == nums[i])
                ++same;
            int N = result.size();

            /*  different from cases when all elements in nums are unique
            	a set can contain 0 ~ same nums[i]
            */
            for (int j = 0; j < N; ++j) {
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