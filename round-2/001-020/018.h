class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp(4);
        for (int i = 0; i < nums.size(); ) {
            for (int j = i + 1; j < nums.size(); ) {

                /*  two pointer's complexity is smaller than two loops
                	meaningless add operation is avoided (tail elements)
                */
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target)
                        ++l;
                    else if (sum > target)
                        --r;
                    else {
                        temp[0] = nums[i], temp[1] = nums[j], temp[2] = nums[l], temp[3] = nums[r];
                        result.push_back(temp);
                        ++l;
                        while (l < r && nums[l] == nums[l - 1]) ++l;
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