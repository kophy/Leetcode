class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2idx;
        for (int i = 0; i < nums.size(); ++i) {
            if (num2idx.count(target - nums[i]))
                return vector<int>( {num2idx[target - nums[i]], i});
            num2idx[nums[i]] = i;
        }
        return vector<int>();
    }
};