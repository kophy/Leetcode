class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> data;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k)
                data.erase(data.find(nums[i - k -1]));
            auto iter = data.lower_bound(nums[i] - t);
            if (iter != data.end() && abs(nums[i] - *iter) <= t)
                return true;
            data.insert(nums[i]);
        }
        return false;
    }
};