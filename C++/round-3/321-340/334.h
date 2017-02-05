class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        vector<int> result;
        result.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (num <= result[0])
                result[0] = num;
            else if (result.size() == 1)
                result.push_back(num);
            else if (num <= result[1])
                result[1] = num;
            else
                return true;
        }
        return false;
    }
};