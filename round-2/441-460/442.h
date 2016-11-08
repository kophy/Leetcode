class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int count[nums.size() + 1] = {0};
        for (auto num : nums)
            if (++count[num - 1] == 2)
                result.push_back(num);
        return result;
    }
};