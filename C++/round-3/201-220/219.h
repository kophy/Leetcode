class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> val2idx;
        for (int i = 0; i < nums.size(); ++i) {
            if (val2idx.find(nums[i]) != val2idx.end() && i - val2idx[nums[i]] <= k)
                return true;
            val2idx[nums[i]] = i;
        }
        return false;
    }
};