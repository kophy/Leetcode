class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int closet = nums[0] + nums[1] + nums[2];
        for (int first = 0; first < nums.size() - 2; ++first) {
            int second = first + 1;
            int third = nums.size() - 1;
            while (second < third) {
                int currsum = nums[first] + nums[second] + nums[third];
                if (abs(currsum - target) < abs(closet - target))
                    closet = currsum;
                if (currsum == target)
                    break;
                else if (currsum > target)
                    --third;
                else
                    ++second;
            }
        }
        return closet;
    }
};