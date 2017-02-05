class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        int i, j, k, l;
        i = 0;
        while (i < nums.size()) {
            j = i + 1;
            while (j < nums.size()) {
                k = j + 1;
                l = nums.size() - 1;
                while (k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target)
                        ++k;
                    else if (sum > target)
                        --l;
                    else {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        result.push_back(temp);

                        ++k;
                        while (k < l && nums[k] == nums[k - 1]) ++k;
                    }
                }
                ++j;
                while (j < nums.size() && nums[j] == nums[j - 1]) ++j;
            }
            ++i;
            while (i < nums.size() && nums[i] == nums[i - 1]) ++i;
        }
        return result;
    }
};