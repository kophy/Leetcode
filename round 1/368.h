class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, vector<int>> dss;
        int max_size = 0;
        int max_index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            dss[i] = vector<int>();
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0) {
                    if (dss[i].size() < dss[j].size()) {
                        dss[i] = dss[j];
                    }
                }
            }
            dss[i].push_back(nums[i]);
            if (dss[i].size() > max_size) {
                max_size = dss[i].size();
                max_index = i;
            }
        }
        return dss[max_index];
    }
};