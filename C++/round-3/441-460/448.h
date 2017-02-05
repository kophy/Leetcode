class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int num : nums)
            nums[abs(num) - 1] = -abs(nums[abs(num) - 1]);
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                result.push_back(i + 1);
        return result;
    }
};