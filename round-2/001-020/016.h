class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int closet = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); ) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target)
                    return target;
                else if (sum < target)
                    ++l;
                else
                    --r;
                if (abs(target - sum) < abs(target - closet))
                    closet = sum;
            }
            ++i;
            while (i < nums.size() && nums[i] == nums[i - 1]) ++i;
        }
        return closet;
    }
};