class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX;
        int c2 = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= c1)
                c1 = nums[i];
            else if (nums[i] <= c2)
                c2 = nums[i];
            else
                return true;
        }
        return false;
    }
};