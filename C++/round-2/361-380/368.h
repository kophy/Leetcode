class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;

        vector<vector<int>> sbs(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && sbs[i].size() < sbs[j].size())
                    sbs[i] = sbs[j];
            }
            sbs[i].push_back(nums[i]);
            result = (result.size() > sbs[i].size())? result : sbs[i];
        }
        return result;
    }
};