class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        map<int, int> count;
        for (int i = 0; i < nums.size(); ++i)
            ++count[nums[i]];
        for (int i = 0; i < nums.size(); ++i)
            if (count[nums[i]] != 2)
                result.push_back(nums[i]);
        return result;
    }
};