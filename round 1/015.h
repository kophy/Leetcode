class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < nums.size()) {
            int target = -nums[i];
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
                if (nums[low] + nums[high] < target)
                    ++low;
                else if (nums[low] + nums[high] > target)
                    --high;
                else {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    result.push_back(temp);

                    while (low < high && nums[low] == temp[1])
                        ++low;
                    while (low < high && nums[high] == temp[2])
                        --high;
                }
            }
            ++i;
            while (i < nums.size() - 2 && nums[i] == nums[i - 1])
                ++i;
        }
        return result;
    }
};