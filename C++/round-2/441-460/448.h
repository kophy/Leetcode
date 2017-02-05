class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> appeared(nums.size(), false);
        for (auto num : nums)
            appeared[num - 1] = true;
        vector<int> result;
        for (int i = 0; i < appeared.size(); ++i)
            if (!appeared[i])
                result.push_back(i + 1);
        return result;
    }
};